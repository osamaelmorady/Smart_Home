/*
 * DIO_Program.c
 *
 *  Created on: Nov 5, 2020
 *      Author: Osama Elmorady
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "LIB/ERROR_STATE.h"
#include "LIB/AVR32_REG.h"


#include "DIO_Private.h"
#include "DIO_Config.h"




/****************************************************************/
/****  Define the direction of Pin as an input or an output  ****/
/****************************************************************/
ErrorState DIO_EnuSetPinDir( u8 Copy_U8PinNumber , u8 Copy_U8PinDir )
{
	ErrorState error = ES_NOK ;

	if ( Copy_U8PinDir == DIO_OUTPUT )
		{

			/** If pin number between pin0 and pin7 set this pin as an output **/
			if ( ( Copy_U8PinNumber >= DIO_PIN0 )  &&  ( Copy_U8PinNumber <= DIO_PIN7 ) )

				{
					SET_BIT ( DIO_DDRA , (Copy_U8PinNumber) ) ;

					error = ES_OK ;
				}


			/** If pin number between pin8 and pin15 set this pin as an output **/
			else if ( ( Copy_U8PinNumber >= DIO_PIN8 )  &&  ( Copy_U8PinNumber <= DIO_PIN15 ) )

				{
					SET_BIT ( DIO_DDRB , ( (Copy_U8PinNumber) - (DIO_PIN8) ) ) ;

					error = ES_OK ;
				}

			/** If pin number between pin16 and pin23 set this pin as an output **/
			else if ( ( Copy_U8PinNumber >= DIO_PIN16 )  &&  ( Copy_U8PinNumber <= DIO_PIN23 ) )

					{
						SET_BIT ( DIO_DDRC , ( (Copy_U8PinNumber) - (DIO_PIN16) ) ) ;

						error = ES_OK ;
					}

			/** If pin number between pin24 and pin31 set this pin as an output **/
			else if ( ( Copy_U8PinNumber >= DIO_PIN24 )  &&  ( Copy_U8PinNumber <= DIO_PIN31 ) )

					{
						SET_BIT(DIO_DDRD , ( (Copy_U8PinNumber) - (DIO_PIN24) ) ) ;

						error = ES_OK ;
					}
			else

				{
				error = ES_OUT_OF_RANGE ;
				}
		}



	else if (Copy_U8PinDir == DIO_INPUT)
		{

			/** If pin number between pin0 and pin7 set this pin as input **/
			if ( ( Copy_U8PinNumber >= DIO_PIN0 )  &&  ( Copy_U8PinNumber <= DIO_PIN7 ) )

				{
					CLR_BIT ( DIO_DDRA ,( (Copy_U8PinNumber) )) ;

					error = ES_OK ;
				}


			/** If pin number between pin8 and pin15 set this pin as input **/
			else if ( ( Copy_U8PinNumber >= DIO_PIN8 )  &&  ( Copy_U8PinNumber <= DIO_PIN15 ) )

				{
					CLR_BIT ( DIO_DDRB , ( (Copy_U8PinNumber) - (DIO_PIN8) ) ) ;

					error = ES_OK ;
				}

			/** If pin number between pin16 and pin23 set this pin as input **/
			else if ( ( Copy_U8PinNumber >= DIO_PIN16 )  &&  ( Copy_U8PinNumber <= DIO_PIN23 ) )

				{
					CLR_BIT ( DIO_DDRC , ( (Copy_U8PinNumber) - (DIO_PIN16)  ) ) ;

					error = ES_OK ;
				}

			/** If pin number between pin24 and pin31 set this pin as input **/
			else if ( ( Copy_U8PinNumber >= DIO_PIN24 )  &&  ( Copy_U8PinNumber <= DIO_PIN31 ) )

				{
					CLR_BIT(DIO_DDRD , ( (Copy_U8PinNumber) - (DIO_PIN24) ) ) ;

					error = ES_OK ;
				}
			else

				{
					error = ES_OUT_OF_RANGE ;
				}

		}


	else
		{
			error = ES_OUT_OF_RANGE ;
		}

	return error ;
}





/************************************/
/****  Define a value on a pin   ****/
/************************************/
ErrorState DIO_EnuSetPinVal(u8 Copy_U8PinNumber , u8 Copy_U8Value)
{
	ErrorState error = ES_NOK ;

	if ( Copy_U8Value == DIO_HIGH )
			{

				/** If pin number between pin0 and pin7 set this pin as an HIGH **/
				if ( ( Copy_U8PinNumber >= DIO_PIN0 )  &&  ( Copy_U8PinNumber <= DIO_PIN7 ) )

					{
						SET_BIT ( DIO_PORTA ,( (Copy_U8PinNumber) ) ) ;

						error = ES_OK ;
					}


				/** If pin number between pin8 and pin15 set this pin as an HIGH **/
				else if ( ( Copy_U8PinNumber >= DIO_PIN8 )  &&  ( Copy_U8PinNumber <= DIO_PIN15 ) )

					{
						SET_BIT ( DIO_PORTB , ( (Copy_U8PinNumber - DIO_PIN8) ) ) ;

						error = ES_OK ;
					}

				/** If pin number between pin16 and pin23 set this pin as an HIGH **/
				else if ( ( Copy_U8PinNumber >= DIO_PIN16 )  &&  ( Copy_U8PinNumber <= DIO_PIN23 ) )

						{
							SET_BIT ( DIO_PORTC , ( (Copy_U8PinNumber - DIO_PIN16) ) ) ;

							error = ES_OK ;
						}

				/** If pin number between pin24 and pin31 set this pin as an HIGH **/
				else if ( ( Copy_U8PinNumber >= DIO_PIN24 )  &&  ( Copy_U8PinNumber <= DIO_PIN31 ) )

						{
							SET_BIT(DIO_PORTD , ( (Copy_U8PinNumber - DIO_PIN24) ) ) ;

							error = ES_OK ;
						}
				else

					{
					error = ES_OUT_OF_RANGE ;
					}
			}



		else if (Copy_U8Value == DIO_LOW)
			{

			/** If pin number between pin0 and pin7 set this pin as an LOW **/
				if ( ( Copy_U8PinNumber >= DIO_PIN0 )  &&  ( Copy_U8PinNumber <= DIO_PIN7 ) )

					{
						CLR_BIT ( DIO_PORTA ,( (Copy_U8PinNumber) ) ) ;

						error = ES_OK ;
					}


				/** If pin number between pin8 and pin15 set this pin as an LOW **/
				else if ( ( Copy_U8PinNumber >= DIO_PIN8 )  &&  ( Copy_U8PinNumber <= DIO_PIN15 ) )

					{
						CLR_BIT ( DIO_PORTB , ( (Copy_U8PinNumber - DIO_PIN8) ) ) ;

						error = ES_OK ;
					}

				/** If pin number between pin16 and pin23 set this pin as an LOW **/
				else if ( ( Copy_U8PinNumber >= DIO_PIN16 )  &&  ( Copy_U8PinNumber <= DIO_PIN23 ) )

					{
						CLR_BIT ( DIO_PORTC , ( (Copy_U8PinNumber - DIO_PIN16) ) ) ;

							error = ES_OK ;
					}

				/** If pin number between pin24 and pin31 set this pin as an LOW **/
				else if ( ( Copy_U8PinNumber >= DIO_PIN24 )  &&  ( Copy_U8PinNumber <= DIO_PIN31 ) )

					{
						CLR_BIT(DIO_PORTD , ( (Copy_U8PinNumber - DIO_PIN24) ) ) ;

							error = ES_OK ;
					}
				else

					{
						error = ES_OUT_OF_RANGE ;
					}

			}


		else
			{
				error = ES_OUT_OF_RANGE ;
			}


	return error ;

}






/*********************************/
/****  Get a value from a pin ****/
/*********************************/
ErrorState DIO_EnuGetPinVal (u8 Copy_U8PinNumber , u32 * Copy_PU8Value)
{
	ErrorState error = ES_NOK ;

	/** If pin number between pin0 and pin7 Get the value on this pin **/
	if ( ( Copy_U8PinNumber >= DIO_PIN0 )  &&  ( Copy_U8PinNumber <= DIO_PIN7 ) )

		{
			* Copy_PU8Value = GET_BIT ( DIO_PINA , ((Copy_U8PinNumber) ) ) ;

			error = ES_OK ;
		}


	/** If pin number between pin8 and pin15 Get the value on this pin **/
	else if ( ( Copy_U8PinNumber >= DIO_PIN8 )  &&  ( Copy_U8PinNumber <= DIO_PIN15 ) )

		{
			* Copy_PU8Value = GET_BIT ( DIO_PINB , ( (Copy_U8PinNumber - DIO_PIN8) ) ) ;

			error = ES_OK ;
		}

	/** If pin number between pin16 and pin23 Get the value on this pin **/
	else if ( ( Copy_U8PinNumber >= DIO_PIN16 )  &&  ( Copy_U8PinNumber <= DIO_PIN23 ) )

		{
			* Copy_PU8Value = GET_BIT ( DIO_PINC , ( (Copy_U8PinNumber - DIO_PIN16) ) ) ;

			error = ES_OK ;
		}

	/** If pin number between pin24 and pin31 Get the value on this pin **/
	else if ( ( Copy_U8PinNumber >= DIO_PIN24 )  &&  ( Copy_U8PinNumber <= DIO_PIN31 ) )

		{
			* Copy_PU8Value = GET_BIT ( DIO_PIND , ( (Copy_U8PinNumber - DIO_PIN24) ) ) ;

			error = ES_OK ;
		}
	else

		{
		error = ES_OUT_OF_RANGE ;
		}

	return error ;
}





/*****************************/
/****  Toggle a pin Value ****/
/*****************************/
ErrorState DIO_EnuTogglePin(u8 Copy_U8PinNumber)
{
	ErrorState error = ES_NOK ;

	/** If pin number between pin0 and pin7 TOGGLE this pin **/
	 if ( ( Copy_U8PinNumber >= DIO_PIN0 )  &&  ( Copy_U8PinNumber <= DIO_PIN7 ) )

	 	{
	 		TOGGLE_BIT ( DIO_PORTA ,( (Copy_U8PinNumber) ) ) ;

	 		error = ES_OK ;
	 	}

	 /** If pin number between pin8 and pin15 TOGGLE this pin **/
	 else if ( ( Copy_U8PinNumber >= DIO_PIN8 )  &&  ( Copy_U8PinNumber <= DIO_PIN15 ) )

	 	{
		 	TOGGLE_BIT ( DIO_PORTB , ( (Copy_U8PinNumber - DIO_PIN8) ) ) ;

		 	error = ES_OK ;
	 	}

	 /** If pin number between pin16 and pin23 TOGGLE this pin **/
	 else if ( ( Copy_U8PinNumber >= DIO_PIN16 )  &&  ( Copy_U8PinNumber <= DIO_PIN23 ) )

	 	{
		 	TOGGLE_BIT ( DIO_PORTC , ( (Copy_U8PinNumber - DIO_PIN16) ) ) ;

		 	error = ES_OK ;
	 	}

	 /** If pin number between pin24 and pin31 TOGGLE this pin **/
	 else if ( ( Copy_U8PinNumber >= DIO_PIN24 )  &&  ( Copy_U8PinNumber <= DIO_PIN31 ) )

	 	{
		 	TOGGLE_BIT (DIO_PORTD , ( (Copy_U8PinNumber) - (DIO_PIN24) ) ) ;

		 	error = ES_OK ;
	 	}
	 else

	 	{
		 error = ES_OUT_OF_RANGE ;
	 	}

	 return error ;
}







/*********************************************/
/********  To set the Port dirction  *********/
/*********************************************/
ErrorState DIO_EnuSetPortDir( u8 Copy_U8PortNum , u8 Copy_U8PortDirectionValue)
{
	ErrorState error=ES_NOK ;

	switch (Copy_U8PortNum)
		{
			case DDRA:  DIO_DDRA = Copy_U8PortDirectionValue  ; error=ES_OK ;	break ;
			case DDRB:  DIO_DDRB = Copy_U8PortDirectionValue  ; error=ES_OK ;	break ;
			case DDRC:  DIO_DDRC = Copy_U8PortDirectionValue  ; error=ES_OK ;	break ;
			case DDRD:  DIO_DDRD = Copy_U8PortDirectionValue  ; error=ES_OK ;	break ;
			default  : 	error=ES_OUT_OF_RANGE ;		       	      	   		    break ;
		}

	return error ;

}





/*********************************************/
/********  To set a value on a port  *********/
/*********************************************/
ErrorState DIO_EnuSetPortVal( u8 Copy_U8PortNum , u8 Copy_U8Value )
{
	ErrorState error=ES_NOK ;

	switch (Copy_U8PortNum)
	{
		case PORTA: DIO_PORTA = Copy_U8Value  ; 	error=ES_OK ;	 break ;
		case PORTB: DIO_PORTB = Copy_U8Value  ; 	error=ES_OK ;	 break ;
		case PORTC: DIO_PORTC = Copy_U8Value  ;		error=ES_OK ; 	 break ;
		case PORTD: DIO_PORTD = Copy_U8Value  ; 	error=ES_OK ;	 break ;
		default : 	error=ES_OUT_OF_RANGE     ;		 		 		 break ;
	}

	return error ;
}




