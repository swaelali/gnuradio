/* -*- c++ -*- */
/*
 * Copyright 2006 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
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

#ifndef INCLUDED_ATSC_INTERLEAVER_H
#define INCLUDED_ATSC_INTERLEAVER_H

#include <gnuradio/atsc/api.h>
#include <gnuradio/atsc/data_interleaver_impl.h>
#include <gnuradio/sync_block.h>

class atsc_interleaver;
typedef boost::shared_ptr<atsc_interleaver> atsc_interleaver_sptr;

ATSC_API atsc_interleaver_sptr atsc_make_interleaver();

/*!  \brief Interleave RS encoded ATSC data ( atsc_mpeg_packet_rs_encoded -->
 * atsc_mpeg_packet_rs_encoded)* \ingroup atsc
 *
 * input: atsc_mpeg_packet_rs_encoded; output: atsc_mpeg_packet_rs_encoded
 */
class ATSC_API atsc_interleaver : public gr::sync_block
{
    friend ATSC_API atsc_interleaver_sptr atsc_make_interleaver();

    atsci_data_interleaver d_interleaver;

    atsc_interleaver();

public:
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);

    void reset()
    { /* nop */
    }
};


#endif /* INCLUDED_ATSC_INTERLEAVER_H */
