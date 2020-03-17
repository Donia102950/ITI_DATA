/*author: donia mohamed
 * version: 1.1
 * type:DIO Driver
 * MC:AVR
 */

/*description: to set the direction of any pin as input or output
 * input: port: 'A','B','C','D'/Pin: from 0 to 7 /direction:1 or 0
 * output : void
 */
void setPinDirection(u8 port,u8 pin,u8 direction);

/*description: to set the value of any pin as high or low
 * input: port: 'A','B','C','D'/Pin: from 0 to 7 /value:1 or 0
 * output : void
 */
void setPinValue(u8 port,u8 pin,u8 val);

/*description: to set the value of any port as high or low
 * input: port: 'A','B','C','D'/value:1 or 0
 * output : void
 */

void setPortValue(u8 port,u8 val);

/*description: to set the direction of any port as high or low
 * input: port: 'A','B','C','D'/value:1 or 0
 * output : void
 */
void setPortDirection(u8 port,u8 val);

/*description: to get the value of any pin
 * input: port: 'A','B','C','D'/pin : from 0 to 7
 * output : value 0 or 1
 */
u8 getPinValue(u8 port,u8 pin);
