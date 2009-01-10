/* -*- c++ -*- */
/*
 * Copyright 2004 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

/*
 * config.h is generated by configure.  It contains the results
 * of probing for features, options etc.  It should be the first
 * file included in your .cc file.
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "bluetooth_multi_block.h"
#include <sys/time.h>

/*
 * Create a new instance of bluetooth_multi_block and return
 * a boost shared_ptr.  This is effectively the public constructor.
 */
bluetooth_multi_block_sptr
bluetooth_make_multi_block ()
{
  return bluetooth_multi_block_sptr (new bluetooth_multi_block ());
}

//private constructor
bluetooth_multi_block::bluetooth_multi_block ()
  : bluetooth_block ()
{
	//FIXME hard-coded stuff:
	double sample_rate = 2000000;	
	double center_freq = 0;	
	int decimation_rate = 2;

	gr_pwr_squelch_cc_sptr squelch = gr_make_pwr_squelch_cc(30.0, 0.01, 0, false);
	std::vector<float> channel_filter = gr_firdes::low_pass(1.0, sample_rate, 500000, 500000, gr_firdes::WIN_HANN);
	gr_freq_xlating_fir_filter_ccf_sptr ddc =
		gr_make_freq_xlating_fir_filter_ccf(decimation_rate, channel_filter, center_freq, sample_rate);
	//ick, this is in python:
	//demod = blks2.gmsk_demod(mu=0.32, samples_per_symbol=samples_per_symbol)
}

//virtual destructor.
bluetooth_multi_block::~bluetooth_multi_block ()
{
}

int 
bluetooth_multi_block::work (int noutput_items,
			       gr_vector_const_void_star &input_items,
			       gr_vector_void_star &output_items)
{
}