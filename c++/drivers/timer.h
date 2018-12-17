#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

typedef uint32_t volatile device_register;

class timer_registers
{
	public:
		enum { TICKS_PER_SEC = 50000000 };
		typedef uint32_t count_type;
		void disable();
		void enable();
		void set(count_type c);
		count_type get() const;
	private:
		enum { TE = 0x01 };
		device_register TMOD;
		device_register TDATA;
		device_register TCNT;
};

inline void timer_registers::disable()
{
	TMOD &= ~TE;
}

inline void timer_registers::enable()
{
	TMOD |= TE;
}

inline void timer_registers::set(count_type c)
{
	TDATA = c;
	TCNT = 0;
}

inline timer_registers::count_type timer_registers::get() const
{
	return TCNT;
}

#endif

#if 0
 As in C, somewhere in your C++ program you should define a pointer to the address of the actual device registers. The prevailing wisdom, with which I agree, is that you should shy away from macros and use a constant pointer, initialized using a reinterpret_cast, as in:


timer_registers *const the_timer
    = reinterpret_cast<timer_registers *>(0xFFFF6000);

Then you can control the timer via member function calls such as:


the_timer->disable();
the_timer->set(timer_registers::TICKS_PER_SEC);
the_timer->enable();

Alternatively, you can use a reference instead of a pointer, defined as:


timer_registers &the_timer
    = *reinterpret_cast<timer_registers *>(0xFFFF6000);

This lets you refer to the_timer as if it were the actual device, rather than a pointer to the device, as in:


the_timer.disable();
the_timer.set(timer_registers::TICKS_PER_SEC);
the_timer.enable();
#endif
