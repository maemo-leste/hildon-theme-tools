/* 
 * GPL license, Copyright (c) 2006 by Nokia Corporation                       
 *                                                                            
 * Authors:                                                                   
 *      Daniel Borgmann <danielb@openismus.com>
 *                                                                            
 * This program is free software; you can redistribute it and/or modify it    
 * under the terms of the GNU General Public License as published by the      
 * Free Software Foundation, version 2.                                                                   
 *                                                                            
 * This program is distributed in the hope that it will be useful, but        
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License   
 * for more details.                                                          
 *                                                                            
 * You should have received a copy of the GNU General Public License along    
 * with this program; if not, write to the Free Software Foundation, Inc., 59 
 * Temple Place - Suite 330, Boston, MA 02111-1307, USA.                      
 *
 */

#include "dither.h"

/* Show some info about basic usage of the tool */
void                            show_usage (void)
{
        g_print ("Usage: %s <inputfile> [outputfile]\n\n", g_get_prgname ());
        g_print ("This tool will apply 16 bit dithering (RGBA 5658) to the specified image.\n"
                  "If you don't specify an output filename, the input file will be overwritten.\n\n");
        g_print ("The tool can save in PNG (.png) and JPEG (.jpg, .jpeg) formats.\n\n");
}

int                             main (int argc, char **argv)
{
        gchar *input_file = NULL;
        gchar *output_file = NULL;
        GdkPixbuf *pixbuf = NULL;
        GError *error = 0;

        g_type_init ();
        g_set_prgname (g_basename (argv [0]));

        if (argc < 2) {
                show_usage ();
                return 1;
        }

        input_file = argv [1];

        if (argc >= 3 && argv [2] != NULL) {
                output_file = argv [2];
        } else {
                output_file = input_file;
        }

        pixbuf = gdk_pixbuf_new_from_file (input_file, &error);
        
        if (error || !pixbuf)
        {
                printf("Failed loading %s...\n", input_file);
                return 1;
        }
        
        save_pixbuf (pixbuf, output_file, TRUE);

        return 0;
}
