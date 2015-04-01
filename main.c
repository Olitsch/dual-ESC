/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <stdio.h> 

enum dir {forward = 0, backward};
enum mot {left = 0, right};
enum index {one = 0, two};

uint16 chanel_value[2] = {1500, 1500};


void run_motor(uint8 motor, uint8 input_value,  uint8 direction)
{
    if (motor == left)
    {
        if (direction == forward)
        {
            Pin_1_0_Write(0xFF);
            Pin_1_1_Write(0x00);
            PWM_1_WriteCompare(input_value);

        }
        else if (direction == backward)
        {
            Pin_1_0_Write(0x00);
            Pin_1_1_Write(0xFF);
            PWM_1_WriteCompare(input_value);
        }
    }
    else if (motor == right)
    {
        if (direction == forward)
        {
            Pin_0_6_Write(0xFF);
            Pin_0_5_Write(0x00);
            PWM_2_WriteCompare(input_value);
        }
        else if (direction == backward)
        {
            Pin_0_6_Write(0x00);
            Pin_0_5_Write(0xFF);
            PWM_2_WriteCompare(input_value);
        }
    }
}




int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    //uint8 uart_rx;
    uint8 motor_value;
    //char8 buffer[15];

    CyGlobalIntEnable;
    PWM_1_Start();
    PWM_2_Start();
    UART_1_Start();
    Timer_CH1_Start();
    Timer_CH2_Start();
    isr_CH1_Start();
    isr_CH2_Start();
    
    for(;;)
    {
        
        /* Place your application code here. */
                
        //LEFT MOTOR --- CH1
        if (chanel_value[one] <1490 && chanel_value[one] >1000)
        {
            motor_value = (1500 - chanel_value[one]) / 2; 
            run_motor(left, motor_value, backward);
            //sprintf(buffer,"CH1 backward %d ", motor_value);
            //UART_1_UartPutString(buffer);
        }
        else if (chanel_value[one] >1510 && chanel_value[one] <2000)
        {
            motor_value = (chanel_value[one] - 1500) / 2; 
            run_motor(left, motor_value, forward);
            //sprintf(buffer,"CH1 forward %d ", motor_value);
            //UART_1_UartPutString(buffer);
        }
        else
        {
            run_motor(left, 0, forward);
        }
        
        CyDelay(5);
        
        //RIGHT MOTOR --- CH2      
        if (chanel_value[two] <1490 && chanel_value[two] >1000)
        {
            motor_value = (1500 - chanel_value[two]) / 2; 
            run_motor(right, motor_value, backward);
        }
        else if (chanel_value[two] >1510 && chanel_value[two] <2000)
        {
            motor_value = (chanel_value[two] - 1500) / 2; 
            run_motor(right, motor_value, forward);
        }
        else
        {
            run_motor(right, 0, forward);
        }
        
        CyDelay(5);
        
        if (pin_button_Read() == 0u)
        {
            Bootloadable_1_Load();
        }
    }
}

/* [] END OF FILE */
