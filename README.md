# Streaming Balloons Demo

* Built using [Z88DK](https://www.z88dk.org/) and SP1.

Lessons learnt:

* [Sevenup image editor](http://metalbrain.speccy.org/) best option for producing sprites - easiest to manage assembler.  [Follow instructions.](https://github.com/z88dk/z88dk/tree/master/libsrc/_DEVELOPMENT/EXAMPLES/zx/demo_sp1)
* Add header information to sprite ASM.
* Add footer/spacer to sprite columns (work out where columns are).

* Columns can be added using [sp1_AddColSpr with a byte offset (graphics) param](https://www.z88dk.org/forum/viewtopic.php?id=10277).  This is poorly documented (tutorials all show explicit assembler labels).

* Tutorials are pretty good for SP1 otherwise.
