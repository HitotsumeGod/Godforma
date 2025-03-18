Command List

FIND [PHRASE] (searches through file for matching phrases and returns number found);

    -ln (provides line numbers for each phrase)
    
    -icase (ignores case when checking phrases)
    
FREP [PHRASE1] [PHRASE2] (performs as FIND; replaces all found instances of P1 with P2; returns number of replacements made);

    -icase (ignores case when checking phrases)
    
RE [PHRASE] (removes all instances of the proferred phrase; does not return);

    -to [NUMBER] (removes only the number proferred)
    
    -icase (ignores case when checking phrases)
    
NAME [FILENAME] (renames the file to the proferred filename; does not return);

MOD [MODE] (sets the mask of the file to the mode proferred; does not return);

DEL [] (permanently deletes the file from the drive; does not return);

SETF [PHRASE1] [PHRASE2] [PHRASE3] [ETC] [FORMATSTRING] (given an arbitrary number of phrases, rewrites the document according to the proferred format string, with the phrases specified using the standard C '%s' specifier);
    
