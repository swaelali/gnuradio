/* -*- c++ -*- */
/*
 * Copyright 2013,2014 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_ZEROMQ_SUB_MSG_SOURCE_IMPL_H
#define INCLUDED_ZEROMQ_SUB_MSG_SOURCE_IMPL_H

#include "zmq.hpp"
#include <gnuradio/zeromq/sub_msg_source.h>

namespace gr {
namespace zeromq {

class sub_msg_source_impl : public sub_msg_source
{
private:
    int d_timeout; // microseconds, -1 is blocking
    zmq::context_t* d_context;
    zmq::socket_t* d_socket;
    boost::thread* d_thread;
    const pmt::pmt_t d_port;

    void readloop();

public:
    bool d_finished;

    sub_msg_source_impl(char* address, int timeout);
    ~sub_msg_source_impl();

    bool start();
    bool stop();
};

} // namespace zeromq
} // namespace gr

#endif /* INCLUDED_ZEROMQ_SUB_MSG_SOURCE_IMPL_H */
