#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set_property("indoors", 1);

    //set_property("no attack", 1); 
    //set_property("no cast", 1);
    //set_property("no scry", 1);
    //set_property("no teleport", 1);
    //set_property("no summon", 1);
    set( "short", "The southern entrance." );
    set( "day long", @EndText
It is dark and gloomy here.

You are standing in the arched doorway which appears to be falling apart. You can hear sounds of screams and human bones snapping into two. The echoing from the chains appears to be closer but traveling from one room to the next.


%^ORANGE%^You begin to smell burning flush%^RESET%^		
	
	%^WHITE%^(30-38+ Level)%^RESET%^
	
EndText);

    set( "night long", @EndText
It is dark and gloomy here.

You are standing in the arched doorway which appears to be faling apart. You can hear sounds of screams and human bones snapping into two. The echoing from the chains appears to be closer but traveling from one room to the next.
	
%^ORANGE%^You begin to smell burning flush%^RESET%^	
	
	%^WHITE%^(30-38+ Level)%^RESET%^
	
EndText);

//add_exit(PATH+"r3.c", "north");
//add_exit(PATH+"r1.c", "bridge");
add_exit(PATH+"r37.c", "enter");
add_exit(PATH+"r4.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
