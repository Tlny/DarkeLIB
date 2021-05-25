inherit "/std/spells/long_term_spell";

void create() {
    ::create();
    set_property("name","summon demon prince");
    set_property("skill","chaos magic");
    set_property("duration", "permanent");
    set_property("casting time",4);
    set_property("base mp cost",311);
    set_property("dev cost", 175);
    set_property("fast dev cost", 481);
    set_property("spell level", 35);
    set_property("moon","luna");
    set_property("caster message","Utilizing the corpse, you open a conduit to the demon world.");
    set_property("target message","");
    set_property("observer message","$C opens a conduit to the demon world.");
    set_property("spell type",({ }));
    set_property("target type", "any");
    set_property("prereq", "summon demon lord");
    set_property("must be present", 1);
    return;
}

void info() {
message("help",
"This spell summons a demon prince.  "
"He will serve you by fighting beside you in combat.  "
"This is a long-term spell (see help long-term), and it takes very much real "
"time to cast.  The spell must be cast on an embalmed corpse of level 35 or higher, which must "
"be prepared with the 'demonic preparation' skill.  If you are interrupted while casting, "
"you may pick up again at a later time.",
this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
  int time;
  if(!at->id("desecrated corpse")) {
    message("info", "You must cast this spell at an embalmed corpse.",
	    caster);
    remove();
    return;
  }
  if((int)at->query_level() < query_property("spell level")) {
    message("info", "You must cast this spell on a desecrated corpse of at least "+
      sprintf("level %d.", query_property("spell level")), caster);
    caster->add_mp(props["mp cost"]);
    remove();
    return;
  }
  if(flag) {
    message("info", "You misdirect the summoning energies and destroy "+
	    "the corpse!", caster);
    message("info", (string)caster->query_cap_name() +
	    " inadvertently crumbles a desecrated corpse to dust.",
	    environment(caster), ({ caster }) );
    at->remove();
    remove();
    return;
  }
time=(12500+((760-(int)caster->query_skill("chaos magic"))*power));
if(archp(caster)) {
time = 1;
}
  set_work_message("%^ORANGE%^You channel chaos power.");
  start_work(at, caster, time, power);
  return;
}

void finish_work(object caster, object at, int power) {
  object ob;

  if(power <= 0) {
    message("info", "BUG in summon spell....unable to complete.",
	    environment(caster));
    remove();
    return;
  }
  message("info", "You summon a Prince from the demonic world.", caster);
  message("info", (string)caster->query_cap_name() + " utters some "+
	  "demonic incantations, and summons "+
	  "a demon prince.",
	  environment(caster), ({ caster }) );
	  if(archp(caster)) {
	    }else{  
	message("info", "%^ORANGE%^%^BOLD%^A loud rumble is heard across the realm as a demon prince is summoned from the demonic world!",
	  users());}
  at->remove();
  seteuid(getuid());
  ob = new("/std/spells/summon/demon_prince");
  ob->set_up(power);
  ob->set_owner((string)caster->query_name());
  ob->move(environment(caster));
  remove();
  return;
}

