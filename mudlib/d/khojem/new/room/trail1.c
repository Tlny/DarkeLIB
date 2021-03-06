//      Wizard:  Khojem
//      trail 1
//      trail1.c

#include <std.h>

inherit ROOM;
void reset() {
	::reset();
    if (!present("half-orc warrior" , this_object()) ) {
      if(random(2)) {
        new("/d/khojem/new/mon/orc_warrior2")->move(this_object());
	  }
	}
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("short", "A wooded path");
    set("long", "You are on a east/west path.  The trees grow "+
      "close around and cut off some of the light from above.\n   \n    \n0--@--0\n    \n   \n"
    );
    add_exit("trail2","east");
    add_exit("clearing","west");
    set_items(([
     ({ "tree","trees", "woods" }) :
        "The trees are large, healthy trees filled with foliage.",
     ({ "leaf","leaves" }) :
        "The leaves sway in the breeze, but still allow much light by them.",
     ({ "trail","path" }) :
        "The trail is worn from frequent use."
     ]));
    set_smell("default", "The smell of growth and decaying wood is everywhere.");
    set_listen("default", "You hear the occasional sound of birds singing.");
}
