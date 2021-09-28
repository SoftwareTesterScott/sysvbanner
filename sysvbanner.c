  /*****************************************************************
 * 
 * SYSVbanner.c
 * 
 * This is a PD version of the SYS V banner program (at least I think 
 * it is compatible to SYS V) which I wrote to use with the clock 
 * program written by:
 **     DCF, Inc.
 **     14623 North 49th Place
 **     Scottsdale, AZ 85254
 * and published in the net comp.sources.misc newsgroup in early July 
 * since the BSD banner program works quite differently.
 * 
 * There is no copyright or responsibility accepted for the use
 * of this software.
 * 
 * Brian Wallis, brw@jim.odr.oz, 4 July 1988
 *
 *****************************************************************/

/* Changes by David Frey, david@eos.lugs.ch, 3 February 1997:
 * 1. protoized and indented, 2. changed @ character to # 
 */

/* Updated by Scott, SoftwareTesterScott@gmail.com , 28 Sep 2010:
 * Increased length text is clipped at from 10 to 30 characters
 * Added comments but left code largely unchanged
 * Changed the text being printed where there was a * instead of #
 * Shortened the length of a glyphs index which was longer than needed
 */

#include <stdio.h>
#include <string.h>
// ASCII characters starting from #32, space as <32 characters arent printable
char *glyphs[] =
{
// Array is 84 x 56 characters, although index 1 is 57 characters long
// It can print 96 possible characters 12 rows of 8 big characters wide
// Each big character is seven "#"s wide and program includes spaces when printing



// 123456_123456_123456_123456_123456_123456_123456_123456_ = 56characters long

// Char
// [-One-][-Two-][Three][Four-][Five-][-Six-][Seven][Eight]

  "         ###  ### ###  # #   ##### ###   #  ##     ###  ",
  "         ###  ### ###  # #  #  #  ## #  #  #  #    ###  ",
  "         ###   #   # ########  #   ### #    ##      #   ",
  "          #            # #   #####    #    ###     #    ",
  "                     #######   #  #  # ####   # #       ",
  "         ###           # #  #  #  # #  # ##    #        ",
  "         ###           # #   ##### #   ### #### #       ",

  "   ##    ##                                            #",
  "  #        #   #   #    #                             # ",
  " #          #   # #     #                            #  ",
  " #          # ### ### #####   ###   #####           #   ",
  " #          #   # #     #     ###           ###    #    ",
  "  #        #   #   #    #      #            ###   #     ",
  "   ##    ##                   #             ###  #      ",

  "  ###     #    #####  ##### #      ####### ##### #######",
  " #   #   ##   #     ##     ##    # #      #     ##    # ",
  "# #   # # #         #      ##    # #      #          #  ",
  "#  #  #   #    #####  ##### ####### ##### ######    #   ",
  "#   # #   #   #            #     #       ##     #  #    ",
  " #   #    #   #      #     #     # #     ##     #  #    ",
  "  ###   ##### ####### #####      #  #####  #####   #    ",

  " #####  #####    #     ###      #           #     ##### ",
  "#     ##     #  # #    ###     #             #   #     #",
  "#     ##     #   #            #     #####     #        #",
  " #####  ######         ###   #                 #     ## ",
  "#     #      #   #     ###    #     #####     #     #   ",
  "#     ##     #  # #     #      #             #          ",
  " #####  #####    #     #        #           #       #   ",

  " #####    #   ######  ##### ###### ############## ##### ",
  "#     #  # #  #     ##     ##     ##      #      #     #",
  "# ### # #   # #     ##      #     ##      #      #      ",
  "# # # ##     ####### #      #     ######  #####  #  ####",
  "# #### ########     ##      #     ##      #      #     #",
  "#     ##     ##     ##     ##     ##      #      #     #",
  " ##### #     #######  ##### ###### ########       ##### ",

  "#     #  ###        ##    # #      #     ##     ########",
  "#     #   #         ##   #  #      ##   ####    ##     #",
  "#     #   #         ##  #   #      # # # ## #   ##     #",
  "#######   #         ####    #      #  #  ##  #  ##     #",
  "#     #   #   #     ##  #   #      #     ##   # ##     #",
  "#     #   #   #     ##   #  #      #     ##    ###     #",
  "#     #  ###   ##### #    # ########     ##     ########",

  "######  ##### ######  ##### ########     ##     ##     #",
  "#     ##     ##     ##     #   #   #     ##     ##  #  #",
  "#     ##     ##     ##         #   #     ##     ##  #  #",
  "###### #     #######  #####    #   #     ##     ##  #  #",
  "#      #   # ##   #        #   #   #     # #   # #  #  #",
  "#      #    # #    # #     #   #   #     #  # #  #  #  #",
  "#       #### ##     # #####    #    #####    #    ## ## ",

  "#     ##     ######## ##### #       #####    #          ",
  " #   #  #   #      #  #      #          #   # #         ",
  "  # #    # #      #   #       #         #  #   #        ",
  "   #      #      #    #        #        #               ",
  "  # #     #     #     #         #       #               ",
  " #   #    #    #      #          #      #               ",
  "#     #   #   ####### #####       # #####        #######",

  "  ###                                                   ",
  "  ###     ##   #####   ####  #####  ###### ######  #### ",
  "   #     #  #  #    # #    # #    # #      #      #    #",
  "    #   #    # #####  #      #    # #####  #####  #     ",
  "        ###### #    # #      #    # #      #      #  ###",
  "        #    # #    # #    # #    # #      #      #    #",
  "        #    # #####   ####  #####  ###### #       #### ",

  "                                                        ",
  " #    #    #        # #    # #      #    # #    #  #### ",
  " #    #    #        # #   #  #      ##  ## ##   # #    #",
  " ######    #        # ####   #      # ## # # #  # #    #",
  " #    #    #        # #  #   #      #    # #  # # #    #",
  " #    #    #   #    # #   #  #      #    # #   ## #    #",
  " #    #    #    ####  #    # ###### #    # #    #  #### ",

  "                                                        ",
  " #####   ####  #####   ####   ##### #    # #    # #    #",
  " #    # #    # #    # #         #   #    # #    # #    #",
  " #    # #    # #    #  ####     #   #    # #    # #    #",
  " #####  #  # # #####       #    #   #    # #    # # ## #",
  " #      #   #  #   #  #    #    #   #    #  #  #  ##  ##",
  " #       ### # #    #  ####     #    ####    ##   #    #",

  "                       ###     #     ###   ##    # # # #",
  " #    #  #   # ###### #        #        # #  #  # # # # ",
  "  #  #    # #      #  #        #        #     ## # # # #",
  "   ##      #      #  ##                 ##        # # # ",
  "   ##      #     #    #        #        #        # # # #",
  "  #  #     #    #     #        #        #         # # # ",
  " #    #    #   ######  ###     #     ###         # # # #"};


int main(int argc, char **argv)
{
  int a;  // row counter, range 0-7
  int b;  // letter counter of word to print
  int c;  // character counter for "#" bigcharacters
  int len; // length
  int ind; // index
  char lineToPrint[240]; // line to be printed out 240x30x8chars per big char

  // For each string passed in as paramater, print all of them
  for (argv++; --argc; argv++) {

    len = strlen(*argv);
    // Cap length to 30
    if (len > 30)
      len = 30;

    for (a = 0; a < 7; a++) { // for each row to be printed
      for (b = 0; b < len; b++) { // for each character to be printed

        // If character to print is non printable (below ASCII number for space=32)
        // print out a space character instead EG: ASCII 7 = Bell , 8 = Backspace
	if ((ind = (*argv)[b] - ' ') < 0)
	  ind = 0;

	for (c = 0; c < 7; c++) {// insert appropriate bigchar symbol to lineToPrint
	  lineToPrint[b * 8 + c] = glyphs[(ind / 8 * 7) + a][(ind % 8 * 7) + c];
	}
	lineToPrint[b * 8 + 7] = ' '; // insert spacer after letters
      }


      // Add null terminators to string from back until reaching a non-space character
      for (b = len * 8 - 1; b >= 0; b--) {
	if (lineToPrint[b] != ' ')
	  break;
	lineToPrint[b] = '\0';
      }
      // Print line to screen
      puts(lineToPrint);
    }
    // Print a blank spacer line
    puts("");
  }
  return 0;
}

