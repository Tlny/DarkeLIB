//      Wizard:  Khojem
//      Dungeon Room 2
//      md_dung2.c

#include <std.h>

inherit VAULT;

void create() {
    int i;
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "Dungeon");
    set("long", 
      "You are in the Donjon's Dungeon.  The floor and "+
      "walls are masoned in large stone blocks.  "+
      "It is dark and the air is damp and musty.  "+
      "You feel uneasy down here and consider retreat. "+
      "A doorway is to the north."
   );
    set_items(([
      ({ "stones", "blocks", "stone", "block", "floor" }) :
        "The stone is rough and damp to the touch.  "+
        "It looks like these stones have been here since the beginning "+
        "of time.  They are large, massive stones.",
      ({ "door","doorway" }) : (: call_other, this_object(), "look_at_door" :),
      ({ "hallway", "hall" }) :
        "The hall is dark and sinister looking.",
        "rat"  :  "You spot a rat running away from you."
      ]));
    add_exit("md_dung1","west");
    add_exit("md_dung2","east");
    add_exit("md_cell1","north");
    set_door("door","/d/khojem/zone/md_cell1","north",0);
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "You hear a rats clawed paws nearby.");
}

void look_at_door() {
    if(query_open("door")) 
      write("The heavy wooden door stands open.\n");
    else write("The heavy wooden door is closed.\n");
}

void rest() {
  set_open("door",0);
  set_locked("door",0);
  "/d/khojem/zone/md_cell1"->set_open("door",0);
  "/d/khojem/zone/md_cell1"->set_locked("door",0);
}
