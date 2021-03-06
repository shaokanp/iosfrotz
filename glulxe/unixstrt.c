/* unixstrt.c: Unix-specific code for Glulxe.
    Designed by Andrew Plotkin <erkyrath@eblong.com>
    http://eblong.com/zarf/glulx/index.html
*/

#include "glk.h"
#include "glulxe.h"
#include "glkstart.h" /* This comes with the Glk library. */

/* The only command-line argument is the filename. */
//static glkunix_argumentlist_t glkunix_arguments[] = {
//  { "", glkunix_arg_ValueFollows, "filename: The game file to load." },
//  { NULL, glkunix_arg_End, NULL }
//};

int glkunix_startup_code_glulxe(glkunix_startup_t *data)
{
  /* It turns out to be more convenient if we return TRUE from here, even 
     when an error occurs, and display an error in glk_main(). */
  char *cx;
  unsigned char buf[12];
  int res;

  if (data->argc <= 1) {
    ginit_err = "You must supply the name of a game file.";
    return FALSE;
  }
  cx = data->argv[1];
    
  gamefile = glkunix_stream_open_pathname(cx, FALSE, 1);
  if (!gamefile) {
    ginit_err = "The game file could not be opened.";
    ginit_err2 = cx;
    return TRUE;
  }

  /* Now we have to check to see if it's a Blorb file. */

  glk_stream_set_position(gamefile, 0, seekmode_Start);
  res = glk_get_buffer_stream(gamefile, (char *)buf, 12);
  if (!res) {
    ginit_err = "The data in this stand-alone game is too short to read.";
    return TRUE;
  }
    
  if (buf[0] == 'G' && buf[1] == 'l' && buf[2] == 'u' && buf[3] == 'l') {
    locate_gamefile(FALSE);
    return TRUE;
  }
  else if (buf[0] == 'F' && buf[1] == 'O' && buf[2] == 'R' && buf[3] == 'M'
    && buf[8] == 'I' && buf[9] == 'F' && buf[10] == 'R' && buf[11] == 'S') {
    locate_gamefile(TRUE);
    return TRUE;
  }
  else {
    ginit_err = "This is neither a Glulx game file nor a Blorb file "
      "which contains one.";
    return TRUE;
  }
}

#if 0 // redundant with git version
extern strid_t gli_stream_open_pathname(char *pathname, int textmode, 
    glui32 rock);

strid_t glkunix_stream_open_pathname(char *pathname, glui32 textmode, 
    glui32 rock)
{
    return gli_stream_open_pathname(pathname, (textmode != 0), rock);
}

int pref_printversion = FALSE;
int pref_screenwidth = 0;
int pref_screenheight = 0;
int pref_messageline = TRUE;
int pref_reverse_textgrids = FALSE;
int pref_window_borders = FALSE;
int pref_precise_timing = FALSE;
int pref_historylen = 20;
int pref_prompt_defaults = TRUE;

#endif
