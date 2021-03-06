//      From Maxwell's Underground mudlib
//        68th Room of Dwarf Mining Zone

#include <std.h>
#include "under.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in an mining tunnel.");
    set("long",@ext 
You are standing in a damp mining tunnel somewhere in the mining complex. 
The rough walls are jagged and cut at sharp angles where the miners dug 
out gems. The passage expands a little here, pushing the walls outward.
    0   
    |   
    @
   /
  0 
ext); 
    set_exits( ({ UNDER+"dm68b", UNDER+"dm68d" }),
      ({"north","southwest" })
    );
    set_items( ([
    "walls" : "The walls are cut and jagged.",
       ]) );
       
    set_smell("default", "You can smell the dust in the air.");
    set_listen("default", "You hear the sounds of mining in the distance.");
}
