//
// wifi.c
// 
// MIT License
//
// Copyright (c) 2019 Caleb Szalacinski
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#include "gpio.h"

void wifi_setup(void)
{
	//GPCLK2 setup
	set_gpio_function(43, FUN_0);
	gpio_pud(PIN(43), PULL_DISABLE);

	//sdhci interface setup
	set_gpio_function(34, FUN_3);
	set_gpio_function(35, FUN_3);
	set_gpio_function(36, FUN_3);
	set_gpio_function(37, FUN_3);
	set_gpio_function(38, FUN_3);
	set_gpio_function(39, FUN_3);
	gpio_pud(PIN(34), PULL_DISABLE);
	gpio_pud(PIN(35) | PIN(36) | PIN(37) | PIN(38) | PIN(39), PULL_UP);


	// So far this covers the pin setup for the wifi IC as described in
	// the device tree file.
}

void wifi_on(void)
{
	set_gpio(WL_ON, 1);
}

void wifi_off(void)
{
	set_gpio(WL_ON, 0);
}
