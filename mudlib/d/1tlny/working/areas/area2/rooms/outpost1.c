// outpost 1

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("ravine6","south");
    add_exit("outpost2","west");
    add_exit("outpost3","east");
    add_exit("outpost5","north");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
