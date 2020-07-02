/***********************************************************************************************************************************/
/*define the interrupts */

#define WWDG 			0
#define PVD				1
#define TAMPER			2
#define RTC				3
#define	FLASH			4
#define RCC				5
#define EXTI0			6
#define EXTI1			7
#define EXTI2			8
#define EXTI3			9
#define EXTI4			10
#define DMA1_CHANNEL1	11
#define DMA1_CHANNEL2	12
#define DMA1_CHANNEL3	13
#define DMA1_CHANNEL4	14
#define DMA1_CHANNEL5	15
#define DMA1_CHANNEL6	16
#define DMA1_CHANNEL7	17
#define ADC1_2 			18
#define CAN1_TX			19
#define CAN1_RX0		20
#define CAN1_RX1		21
#define CAN1_SCE		22
#define EXTI9_5			23
#define TIM1_BRK		24
#define TIM1_UP			25
#define TIM1_TRG_COM	26
#define TIM1_CC			27
#define TIM2			28
#define TIM3			29
#define TIM4			30
#define I2C1_EV			31
#define I2C1_ER			32
#define I2C2_EV			33
#define I2C2_ER			34
#define SPI1			35
#define SPI2			36
#define USART1			37
#define USART2			38
#define USART3			39
#define EXTI5_10		40
#define RTCALARM		41
#define OTG_FS_WKUP		42
#define TIM5			50
#define SPI3			51
#define UART4			52
#define UART5			53
#define TIM6			54
#define TIM7			55
#define DMA2_CHANNEL1	56
#define DMA2_CHANNEL2	57
#define DMA2_CHANNEL3	58
#define DMA2_CHANNEL4	59
#define DMA2_CHANNEL5	60
#define ETH				61
#define ETH_WKUP		62
#define CAN2_TX			63
#define CAN2_RX0		64
#define CAN2_RX1		65
#define CAN2_SCE		66
#define OTG_FS			67 

/*defines of priority group */
#define PREEMPTION_ONLY                0x00000300
#define THREE_PREEMPTION_ONE_SUBGROUP  0x00000400
#define TWO_PREEMPTION_TWO_SUBGROUP    0x00000500
#define ONE_PREEMPTION_THREE_SUBGROUP  0x00000600
#define SUBGROUP_ONLY                  0x00000700

/*enable function */
u8 NVIC_uint8enableInterrupt(u8 Interrupt_Number);

/*Disable function */
u8 NVIC_uint8disableInterrupt(u8 Interrupt_Number);

/*to set the pending flag*/
u8 NVIC_uint8setPending(u8 Interrupt_Number);

/*to reset the pending flag*/
u8 NVIC_uint8clearPending(u8 Interrupt_Number);

/*to get the Active bit*/
u8 NVIC_uint8getActive(u8 Interrupt_Number , u8 *value);

/*to get the pending flag*/
u8 NVIC_uint8getPending(u8 Interrupt_Number ,u8 *value);

/*to set the Priority Group*/
u8 NVIC_uint8setPriorityGroup(u32 Priority);

/*to set the Priority of any Interrupt*/
u8 NVIC_uint8setPriority(u8 Interrupt_Number , u8 Priority);

/*to get the Priority of any Interrupt*/
u8 NVIC_uint8getPriority(u8 Interrupt_Number , u8 *Priority);

/*Disable fault interrupts*/
void NVIC_voiddisbaleFaultInterrupt(void);

/*to enable any all fault interrupt*/
void NVIC_voidenableFaultInterrupt(void);


/*Enable Peripheral Interrupts*/
void NVIC_voidenablePeripheralInterrupt(void);

/*Disables Peripheral Interrupts (GIE = 0)*/
void NVIC_voiddisablePeripheralInterrupt(void);

/*to set the priority base but still under test */
/*void NVIC_uint8setPioritybase(u32 Copy_PriorityIndex) ;*/

