inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name","unholy armour");
    set_property("stack key", "unholy armour");
    set_property("stack num", 2);
    set_property("skill","black magic");
    set_property("casting time",10);
   set_property("base mp cost", 100);
    set_property("dev cost", 130);
    set_property("fast dev cost", 390);
    set_property("spell level", 25);
    set_property("moon","luna");
    set_property("caster message","You cast unholy armour.");
    set_property("target message"," ");
    set_property("observer message","$C casts unholy armour.");
    set_property("spell type",({ "protection" }));
    set_property("protection types",
        ([ "cutting" : 175, "impaling" : 175, "crushing" : 175,
            "impact" : 175, "strike" : 175, "cold" : 175, "unholy" : 175, "disruption" : 175 ]));
    set_property("target type", "living");
    set_property("no target", 1);
    set_property("must be present", 1);
    set_property("prereq", "freeze skin");
    set_property("duration", 180);
    return;
}

void info() {
message("help",
"Welcome to the most powerful physical damage protection spell on the mud.  "
"It imbues the target with protection from ALL PHYSICAL DAMAGE (cutting, impact, etc.). This spell is self cast only and may be stacked 2 times.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

  at = caster;

  ::spell_func(caster, at, power, args, flag);

  return;

}

