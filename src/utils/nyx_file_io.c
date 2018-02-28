// Copyright (c) 2010-2018 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0
/**
 *******************************************************************************
 * @file nyx_file_io.c
 *
 * @brief nyx file io implementation
 *
 *******************************************************************************
 */

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <errno.h>

#include <nyx/module/nyx_log.h>
#include "msgid.h"

#define READ_BUFFER_SIZE 20

int32_t nyx_utils_read_value(char *path)
{
	int32_t val = -1;
	int32_t converted;
	char buffer[READ_BUFFER_SIZE];
	char *endptr = NULL;
	ssize_t r = -1;

	if (!path)
	{
		return -1;
	}

	int fd = open(path, O_RDONLY);

	if (fd >= 0)
	{
		do
		{
			r = read(fd, buffer, READ_BUFFER_SIZE - 1);
		}
		while (r < 0 && EINTR == errno);

		close(fd);

		if (r > 0)
		{
			// NUL_terminate the buffer and try to convert.
			buffer[r] = '\0';
			converted = (int32_t) strtol(buffer, &endptr, 10);

			if (endptr != buffer)
			{
				val = converted;
			}
		}
	}

	return val;
}

int32_t nyx_utils_read(char *path, char *buf, size_t size)
{
	if (!path || !buf || size == 0)
	{
		return -1;
	}

	if (size == 1)
	{
		buf[0] = '\0';
		return 0;
	}

	int fd = open(path, O_RDONLY);

	if (fd == -1)
	{
		return -1;
	}

	ssize_t count = read(fd, buf, size - 1);

	if (count > 0)
	{
		while (count > 0 && buf[count - 1] == '\n')
		{
			count--;
		}

		if (count >= size)
		{
			count = size - 1;
		}

		buf[count] = '\0';
	}
	else
	{
		buf[0] = '\0';
	}

	close(fd);
	return count;
}

void nyx_utils_write_value(char *path, int32_t val)
{
	if (!path)
	{
		return;
	}

	int fd = open(path, O_WRONLY);

	if (fd >= 0)
	{
		char buffer[READ_BUFFER_SIZE];
		snprintf(buffer, READ_BUFFER_SIZE, "%" PRIi32, val);

		ssize_t written;
		size_t to_write = strlen(buffer);

		do
		{
			written = write(fd, buffer, to_write);
		}
		while (written < to_write && EINTR == errno);

		if (written < to_write)
		{
			nyx_error(MSGID_NYX_UTIL_WRITE_VAL_ERR, 0,
			          "Could not write value %d to file/device at %s", val, path);
		}

		close(fd);
	}
}

void nyx_utils_write(char *path, char *buf, size_t size)
{
	if (!path || !buf || size == 0)
	{
		return;
	}

	int fd = open(path, O_WRONLY);

	if (fd == -1)
	{
		return;
	}

	ssize_t written;

	do
	{
		written = write(fd, buf, size);
	}
	while (written < size && EINTR == errno);

	if (written < size)
	{
		nyx_error(MSGID_NYX_UTIL_WRITE_ERR, 0, "Could not write to file/device at %s",
		          path);
	}

	close(fd);
}
