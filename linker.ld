ENTRY(_start)

__stack_size = 2048;

MEMORY
{
	ram : ORIGIN = 0x80000000, LENGTH = 1M
}

SECTIONS
{
	.text : 
	{
		*(.text .text.*)
	} > ram
	
	.data :
	{
		*(.sdata .sdata.*)
		*(.data .data.*)
	} > ram
	
	.rodata : 
	{
		*(.rodata .rodata.*)
	} >ram

	.bss : 
	{
		*(.sbss .sbss.*) 
		*(.bss .bss.*)
	} > ram
	
	.stack_0 :
	{
		PROVIDE( _sstack0 = . );
		. = . + __stack_size;
		PROVIDE( _estack0 = .);
	} >ram
	
	.stack_1 :
	{
		PROVIDE( _sstack1 = . );
		. = . + __stack_size;
		PROVIDE( _estack1 = .);
	} >ram		
}