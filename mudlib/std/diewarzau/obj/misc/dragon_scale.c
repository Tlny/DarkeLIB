inherit "/std/Object";

int level;

void create() {
  ::create();
  set_name("dragon scale");
  set_id(({ "scale", "dragon scale", "scales" }));
  set_short("a dragon scale");
  set_long("These scales are used to create a dragon.");
  set_weight(40);
  set_value(2);
  return;
}
