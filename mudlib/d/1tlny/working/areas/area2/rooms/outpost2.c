// outpost 2

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("outpost4","north");
    add_exit("outpost1","east");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
