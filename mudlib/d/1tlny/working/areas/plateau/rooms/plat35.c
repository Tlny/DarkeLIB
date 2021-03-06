
#include <std.h>
#include </wizards/garetjax/plateau/defs.h>

inherit PLATROOMS + "jumpoff.c";

void create() {
    ::create();
    set_property("light", 2);
    set_property("outdoors", 1);
    set("short", "The Savanah Plateau");
   set_long( "\nYou are on a grassy plateau which stretches out in "
   "front of you, and ends abruptly to the east of you in a deadly drop."
   " The jump down looks quite enticing, if you are in a hurry."
    " There is a plank, sticking off the plateau, from which those centaurs that are deemed unworthy to serve Balrog are pushed to their death."
    );
    set_exits( ({  "plat36.c", "plat34.c", "plat22.c" }),
      ({"north",  "west", "south" })
    );
    add_item("plank", "A long thin board, which juts over the edge of the plateau.");
    set_smell("default", "The air smells like freshly dug up dirt.");
    set_listen("default", "The"  
   " galloping of horses is deafening.");
  }

 void reset()   {
      ::reset(); 
      new(PLATMON + "ctmage")->move(this_object());
}

