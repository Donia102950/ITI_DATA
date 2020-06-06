**Project Description**

This project aims to make memory section specified to only one variable to be
saved every time in the same place in memory

**Steps**

1) First we need to make specific memory in mem.Id file as shown : DONIA (xrw) :
ORIGIN = 0x20000000, LENGTH = 4

2) Then we need to make specific section in section.Id as shown :

.dx : ALIGN(4)

{

KEEP(\*(.dx)) /\* donia part \*/

} \>DONIA

3) Then we need to set compiler instruction as shown :

**\__attribute_\_** ((section(".*dx*"),used))uint8_t doniaa;

4) Then check the file .map after compiling to make sure that variable in memory
Donia for Example :
