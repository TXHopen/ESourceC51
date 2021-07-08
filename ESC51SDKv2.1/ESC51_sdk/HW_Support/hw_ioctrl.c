#include "hw_ioctrl.h"

#ifdef IOCTRL_CONFIG


/* ------------------------------------------------------------ */



/* ------------------------------------------------------------ */




char io_ctrl_set_mode (IOPort Port, IOBit Bit, IOMode mode)
{
    switch (Port)
    {
        case IO_P0: 
            switch (mode)
            {
                case IO_IN_OUT_PUT:
                    IO_P0M0 = IO_IN_OUT_PUT_M0 << Bit;
                    IO_P0M1 = IO_IN_OUT_PUT_M1 << Bit;
                    break;
                case IO_OUT_PUT_PP:
                    IO_P0M0 = IO_OUT_PUT_PP_M0 << Bit;
                    IO_P0M1 = IO_OUT_PUT_PP_M1 << Bit;
                    break;
                case IO_IN_PUT_ONLY:
                    IO_P0M0 = IO_IN_PUT_ONLY_M0 << Bit;
                    IO_P0M1 = IO_IN_PUT_ONLY_M1 << Bit;
                    break;
                case IO_OPEN_DRAIN:
                    IO_P0M0 = IO_OPEN_DRAIN_M0 << Bit;
                    IO_P0M1 = IO_OPEN_DRAIN_M1 << Bit;
                    break;
                default:
                    break;
            }
            break;
        case IO_P1: 
            switch (mode)
            {
                case IO_IN_OUT_PUT:
                    IO_P1M0 = IO_IN_OUT_PUT_M0 << Bit;
                    IO_P1M1 = IO_IN_OUT_PUT_M1 << Bit;
                    break;
                case IO_OUT_PUT_PP:
                    IO_P1M0 = IO_OUT_PUT_PP_M0 << Bit;
                    IO_P1M1 = IO_OUT_PUT_PP_M1 << Bit;
                    break;
                case IO_IN_PUT_ONLY:
                    IO_P1M0 = IO_IN_PUT_ONLY_M0 << Bit;
                    IO_P1M1 = IO_IN_PUT_ONLY_M1 << Bit;
                    break;
                case IO_OPEN_DRAIN:
                    IO_P1M0 = IO_OPEN_DRAIN_M0 << Bit;
                    IO_P1M1 = IO_OPEN_DRAIN_M1 << Bit;
                    break;
                default:
                    break;
            }
            break;
        case IO_P2: 
            switch (mode)
            {
                case IO_IN_OUT_PUT:
                    IO_P2M0 = IO_IN_OUT_PUT_M0 << Bit;
                    IO_P2M1 = IO_IN_OUT_PUT_M1 << Bit;
                    break;
                case IO_OUT_PUT_PP:
                    IO_P2M0 = IO_OUT_PUT_PP_M0 << Bit;
                    IO_P2M1 = IO_OUT_PUT_PP_M1 << Bit;
                    break;
                case IO_IN_PUT_ONLY:
                    IO_P2M0 = IO_IN_PUT_ONLY_M0 << Bit;
                    IO_P2M1 = IO_IN_PUT_ONLY_M1 << Bit;
                    break;
                case IO_OPEN_DRAIN:
                    IO_P2M0 = IO_OPEN_DRAIN_M0 << Bit;
                    IO_P2M1 = IO_OPEN_DRAIN_M1 << Bit;
                    break;
                default:
                    break;
            }
            break;
        case IO_P3: 
            switch (mode)
            {
                case IO_IN_OUT_PUT:
                    IO_P3M0 = IO_IN_OUT_PUT_M0 << Bit;
                    IO_P3M1 = IO_IN_OUT_PUT_M1 << Bit;
                    break;
                case IO_OUT_PUT_PP:
                    IO_P3M0 = IO_OUT_PUT_PP_M0 << Bit;
                    IO_P3M1 = IO_OUT_PUT_PP_M1 << Bit;
                    break;
                case IO_IN_PUT_ONLY:
                    IO_P3M0 = IO_IN_PUT_ONLY_M0 << Bit;
                    IO_P3M1 = IO_IN_PUT_ONLY_M1 << Bit;
                    break;
                case IO_OPEN_DRAIN:
                    IO_P3M0 = IO_OPEN_DRAIN_M0 << Bit;
                    IO_P3M1 = IO_OPEN_DRAIN_M1 << Bit;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
	
	return 0;
}



char io_ctrl_set_high (IOPort Port, IOBit Bit)
{
    switch (Port)
    {
        case IO_P0:P0 = P0 | (0x01 << Bit);break;
        case IO_P1:P1 = P1 | (0x01 << Bit);break;
        case IO_P2:P2 = P2 | (0x01 << Bit);break;
        case IO_P3:P3 = P3 | (0x01 << Bit);break;
        default:break;
    }

    return 0;
}

char io_ctrl_set_low (IOPort Port, IOBit Bit)
{
    switch (Port)
    {
        case IO_P0:P0 = P0 & ~(0x01 << Bit);break;
        case IO_P1:P1 = P1 & ~(0x01 << Bit);break;
        case IO_P2:P2 = P2 & ~(0x01 << Bit);break;
        case IO_P3:P3 = P3 & ~(0x01 << Bit);break;
        default:break;
    }

    return 0;
}

char io_ctrl_read (IOPort Port, IOBit Bit)
{
    char status = -1;

    switch (Port)
    {
        case IO_P0:status  = P0;
                   status &= (0x01 << Bit);
                   break;
        case IO_P1:status  = P1;
                   status &= (0x01 << Bit);
                   break;
        case IO_P2:status  = P2;
                   status &= (0x01 << Bit);
                   break;
        case IO_P3:status  = P3;
                   status &= (0x01 << Bit);
                   break;
        default:break;
    }

    return status;
}







#endif /* IOCTRL_CONFIG */