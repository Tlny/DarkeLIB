#include <dirs.h>
#include <std.h>
#include "../monk.h"
inherit ROOM;

void create() {
  ::create();
   set_property("light",2);
   set_property("indoors",1);
   add_exit(MONKROOMS+"room27", "north");
   set("short","A large hut\n   0\n   | \n   @   \n     \n    \n");
   set("long",
"This is the living quarters of a monk, the hut is large "
"and well furnished.  A large bed lies in the back of the room, "
"it's coverings soft.  This hut seems to belong to a more "
"powerful and influential monk, as it's bigger then others in "
"the village.\n   0\n   | \n   @   \n     \n    \n");
}

void reset() {
  ::reset();
   if(!present("woman"))
   new(MONKMOBS+"monk_woman.c")->move(this_object());
   if(!present("trainer"))
   new(MONKMOBS+"monk3.c")->move(this_object());
}
