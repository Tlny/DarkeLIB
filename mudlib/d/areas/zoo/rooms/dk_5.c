#include <std.h>
#include "../zoo.h"

inherit ROOM;

void create() {
	::create();
	set_short("Elemental Keep");
	set_long("The Elemental Keep. \n");
	set_property("light", 3);
	set_property("indoors", 2);
	set_smell("default", "It smells surprisingly fresh.");
	set_listen("default", "You hear loud screeches.");
	set_exits( ({
	"dk_2.c"
	         }),
	({"north"}));
}
void reset() {
	::reset();
	if(!present("elemental dragon")) {
	new(MON+"ele_dragon.c")->move(this_object());
	new(MON+"ele_dragon.c")->move(this_object());
	new(MON+"ele_dragon.c")->move(this_object());
	new(MON+"ele_dragon.c")->move(this_object());

    }
}
