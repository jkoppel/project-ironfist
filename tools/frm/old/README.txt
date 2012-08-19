Creature Form files tell the game how to treat a creature graphically. In particular, it gives the correspondence between animations in the game, and the raw frames in the ICN file. It also contains other information, such as the location of the creature's eyes (for the Blind spell animation), and how long the walk cycle takes.

In this directory is a SynalyzeIt grammar file for CreatureForm files. SynalyzeIt  (http://www.synalysis.net/) is a free structured hex-editor for Mac. Combined with the grammar file, it becomes a very effective editor for Creature Form files.

It is currently incomplete, and slightly mistaken. For example, since creating this file, we have discovered that, while the Walk animation has animation-code 7, the different pieces (beginning, middle, end) of the Walk animation are actually stored in animation 0-6, and are pieced together by the game.
