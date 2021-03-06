/*
// This file is part of the TMI Mudlib distribution
// Please include this header if you use this code.
// Written by Sulam(1-8-92)
// Help added (1/28/92) by Brian
*/

#include <std.h>
inherit DAEMON;

int help();

int 
cmd_rmdir(string str)
{
	seteuid(geteuid(previous_object()));
	if( !str )
	{
                return help();
	}
	str = resolv_path(this_player()->get_path(), str);
	switch( file_size(str) )
	{
		case -1:
			notify_fail("rmdir: "+str+": No such file.\n");
			return 0; break;
		case -2:
			break;
		default:
			notify_fail("rmdir: "+str+": not a directory.\n");
			return 0; break;
	}
 if( (int)master()->valid_write(str, this_object(), "rmdir") == 0 )
	{
		notify_fail(str+": Permission denied.\n");
		return 0;
	}
	write(rmdir(str) ? "Ok.\n" : str+": couldn't remove directory.\n");
	return 1;
}

int
help() {
  write("Command: rmdir\nSyntax: rmdir <directory>\n"+
        "This command allows you to remove the specified directory.  If\n"+
        "the directory is not empty then the command will fail.\n");
  return 1;
}
/* EOF */
