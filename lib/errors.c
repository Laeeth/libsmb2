/* -*-  mode:c; tab-width:8; c-basic-offset:8; indent-tabs-mode:nil;  -*- */
/*
   Copyright (C) 2016 by Ronnie Sahlberg <ronniesahlberg@gmail.com>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation; either version 2.1 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program; if not, see <http://www.gnu.org/licenses/>.
*/

#include <errno.h>
#include <stdint.h>

#include "smb2.h"

const char *nterror_to_str(uint32_t status) {
        switch (status) {
        case SMB2_STATUS_SUCCESS:
                return "STATUS_SUCCESS";
        case SMB2_STATUS_NO_MORE_FILES:
                return "STATUS_NO_MORE_FILES";
        case SMB2_STATUS_MORE_PROCESSING_REQUIRED:
                return "STATUS_MORE_PROCESSING_REQUIRED";
        case SMB2_STATUS_LOGON_FAILURE:
                return "STATUS_LOGON_FAILURE";
        case SMB2_STATUS_NOT_A_DIRECTORY:
                return "STATUS_NOT_A_DIRECTORY";
        default:
                return "Unknown";
        }
}

int nterror_to_errno(uint32_t status) {
        switch (status) {
        case SMB2_STATUS_SUCCESS:
                return 0;
        case SMB2_STATUS_MORE_PROCESSING_REQUIRED:
                return EAGAIN;
        case SMB2_STATUS_NO_MORE_FILES:
                return ENODATA;
        case SMB2_STATUS_LOGON_FAILURE:
                return ECONNREFUSED;
        case SMB2_STATUS_NOT_A_DIRECTORY:
                return ENOTDIR;
        default:
                return EIO;
        }
}
