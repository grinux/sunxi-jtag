#include <LowLevelIOInterface.h>
#include <serial.h>

/* redefine iar __write() used by printf to serial console output */

unsigned int __write(int handle, 
                     const unsigned char * buffer, 
                     unsigned int size)
{
        unsigned int chars = size;
        
        if (buffer == 0) {
                /*
                * This means that we should flush internal buffers.  Since we
                * don't we just return.  (Remember, "handle" == -1 means that all
                * handles should be flushed.)
                */
                return 0;
        }
        
        /* This template only writes to "standard out" and "standard err",
        * for all other file handles it returns failure. */
        if (handle != _LLIO_STDOUT && handle != _LLIO_STDERR) {
                return _LLIO_ERROR;
        }       
#if !DRAM_APP
        if (gd->flags & GD_FLG_SERIAL_READY) {
                if (gd->flags & GD_FLG_RECORD_OVF) {
                        serial_puts("\n\nPreinit buffer overflow\n\n");
                        gd->flags &= ~GD_FLG_RECORD_OVF;
                        gd->cb_size = 0;
                } else if (gd->cb_size > 0) {
                        serial_puts("\n--\n"); /* mark buffered output */
                        for (int i = 0; gd->cb_size != 0; --gd->cb_size)
                                serial_putc(gd->cb[i++]);
                        serial_puts("--\n");
                }
#endif                
                for (; size != 0; --size)  
                        serial_putc(*buffer++);              
#if !DRAM_APP 
        } else { /* collect output in console buffer gd->cb until serial
                  * will be ready 
                  */
                for (; size != 0 && gd->cb_size < sizeof(gd->cb) ; --size)  
                        gd->cb[gd->cb_size++] = *buffer++;
                if (gd->cb_size == sizeof(gd->cb))
                        gd->flags |= GD_FLG_RECORD_OVF;
                        
        }
#endif        
        return chars;
}
