//      Wizard:  Khojem
//      hou6.c

#include <std.h>

inherit VAULT;

int check_mobs();
int my_mob_filter(object mob);

int check_mobs() {
  object *all;

  all = filter_array(livings(), "my_mob_filter", this_object());
  if(!all) return 0;
  return sizeof(all);
}

int my_mob_filter(object mob) {
  if(base_name(mob) == "/wizards/khojem/port/mon/citizen2")  
    return 1;                                        
  return 0;
}

void reset(){
  ::reset();
  if(!present("citizen")) {
    if(check_mobs()<5)
      new("/wizards/khojem/port/mon/citizen2")->move(this_object());
  }
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "A small house");
    set("long", "This small, little house is clean and well maintained.  "+
      "The woodwork is well cared for and cleaned regularly.  The individual "+
      "owning this home must be wealthy enough to afford the expensive maintaince."
    );
    add_exit("/wizards/khojem/port/room/s21","east");
    set_door("mauve door","/wizards/khojem/port/room/s21","east",0);
    set_func("mauve door","open","do_open");
    set_func("mauve door","close","do_close");
    set_items(([
     ({ "mauve door", "door" }) :
        (: call_other, this_object(), "look_at_door" :)
    ]));
    set_smell("default", "A musty smell fills the air.");
    set_listen("default", "The house is quiet.");
}

void look_at_door() {
  if(query_open("mauve door")) 
    write("The mauve door is wide open.\n");
  else 
    write("The mauve door is closed.\n");
  say(this_player()->query_cap_name()+" examines a mauve door.\n");
}

int do_open() {
  remove_invis_exit("east");
  "/wizards/khojem/port/room/s21"->remove_invis_exit("west");
  write("A mauve door swings wide open.\n");
  say(this_player()->query_cap_name()+" opens a mauve door.\n");
  return 1;
}
 
int do_close() {
  add_invis_exit("east");
  "/wizards/khojem/port/room/s21"->add_invis_exit("west");
  write("A mauve door is slammed shut.\n");
  say(this_player()->query_cap_name()+" slams a mauve door shut.\n");
  return 1;
}

