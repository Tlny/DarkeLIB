// upath 2

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("long", "LONG "+
      "LONG.");
    add_item("ITEM","DESC.");
    add_exit("upath1","north");
    add_exit("upath3","west");

    set_smell("default", "SMELL.");
    set_listen("default", "SOUND.");
}
