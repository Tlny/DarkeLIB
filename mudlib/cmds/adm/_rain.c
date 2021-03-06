/*  /cmds/creator/_rain.c
 *  Made for DarkeMUD
 *  Created by Geldron 031096
 *  Copyright (c) 1996, DarkeMUD
 *  Do not remove this header
 */


inherit DAEMON;

int cmd_rain(string arg) {
    object *tmp;
    int i;

    tmp = users();
    if(!arg) {
	message("rain", syntax("rain FILENAME"), TP);
	return 1;
    }
    seteuid(geteuid(TP));
    arg = resolv_path(arg);
    if(file_size(arg) < 1) 
	arg = TP->get_path() + "/" + arg;
    if(file_size(arg) < 1)
	arg = arg + ".c";
    if(file_size(arg) < 1) {
	message("rain", arg + " doesn't exist.", TP);
	seteuid(0);
	return 1;
    }
    message("rain", "You rain " + arg + ".", TP);
    for(i = 0; i < sizeof(tmp); i++) {
	new(arg)->move(tmp[i]);
	message("rain", "Something lands into your inventory "
	  "making a loud PLOP sound.", tmp[i]);
    }
    seteuid(getuid());
    if(!archp(TP))
	log_file("rain", getuid(TP) + " rained " + arg + " at " +
	  ctime(time()) + ".\n");
    return 1;
}

void help() {
    message("rain_help", syntax("rain FILENAME") + "\n\n"
      "Clones FILENAME to everyone on the MUD.", TP);
}
