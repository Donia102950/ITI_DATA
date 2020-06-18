**Project Description**

This project aims to make memory section specified to only one variable to be
saved every time in the same place in memory

**Steps**

1.  First we need to make specific memory in mem.Id file as shown : DONIA (xrw)

![](media/035bd04a0de8ffff5e5781c57fb4424b.png)

2.  Then we need to make specific section in section.Id as shown :

.dx : ALIGN(4)

{

>   KEEP(\*(.dx)) /\* donia part \*/

} \>DONIA

![C:\\Users\\DELL\\Pictures\\Screenshots\\Screenshot (453).png](media/9b0c3d09c6a4734a786b2ebed18d1867.png)

3.  Then we need to set compiler instruction as shown :

>   **\_attribute\_** ((section(".*dx*"),used))uint8_t doniaa;

4.  Then check the file .map after compiling to make sure that variable in
    memory Donia for Example :

![](media/1a1b7f118f8d0111f8dc807107d5b866.png)
