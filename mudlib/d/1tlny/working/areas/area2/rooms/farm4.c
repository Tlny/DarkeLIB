// farm 4

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("farm2","west");
    add_exit("farm5","south");
    add_exit("farm6","east");
    add_exit("house1","north");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
