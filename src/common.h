/* 
 * GPL license, Copyright (c) 2006 by Nokia Corporation                       
 *                                                                            
 * Authors:                                                                   
 *      Michael Dominic Kostrzewa <michael.kostrzewa@nokia.com>               
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

#include <glib.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

#define  JPEG_QUALITY "99"

struct                          _Template 
{
        gint Width;
        gint Height;
        GSList *ElementList;
        GSList *ColorList;
} typedef                       Template;

struct                          _Element 
{
        gchar *Name;
        gint X;
        gint Y;
        gint Width;
        gint Height;
        gint XBorder;
        gint BorderTop;
        gint BorderBottom;
        gint BorderLeft;
        gint BorderRight;
        gboolean ForcedAlpha;
        gboolean NoAlpha;
        
} typedef                       Element;

struct                          _Color
{
        gchar *Name;
        gint X;
        gint Y;
} typedef                       Color;
 
Template*                       read_template (gchar *template_file);

Element*                        new_element_from_key (GKeyFile *key_file, gchar *name);

void                            free_element (Element *element);

void                            free_color (Color *color);

void                            show_template (Template *templ);

Color*                          new_color_from_key (GKeyFile *key_file, gchar *name);

void                            free_template (Template *templ);

void                            dither_pixbuf (GdkPixbuf *pixbuf);

void                            save_pixbuf (GdkPixbuf *pixbuf, gchar *filename, gboolean dither);
