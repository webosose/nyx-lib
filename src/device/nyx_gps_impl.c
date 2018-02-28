// Copyright (c) 2013-2018 LG Electronics, Inc.
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

#include "nyx_device_impl.h"
#include <nyx/module/nyx_device_internal.h>

nyx_error_t nyx_gps_init(nyx_device_handle_t handle,
                         nyx_gps_callbacks_t *gps_cbs,
                         nyx_gps_xtra_callbacks_t *xtra_cbs,
                         nyx_agps_callbacks_t *agps_cbs,
                         nyx_gps_ni_callbacks_t *gps_ni_cbs,
                         nyx_agps_ril_callbacks_t *agps_ril_cbs,
                         nyx_gps_geofence_callbacks_t *geofence_cbs)
{
	nyx_execute_return_function(gps_init, GPS, INIT, handle,
	                            gps_cbs, xtra_cbs, agps_cbs, gps_ni_cbs, agps_ril_cbs, geofence_cbs);
}

nyx_error_t nyx_gps_start(nyx_device_handle_t handle)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	CHECK_DEVICE_TYPE(d, NYX_DEVICE_GPS);
	nyx_gps_start_function_t f_ptr = LOOKUP_METHOD(d, NYX_GPS_START_MODULE_METHOD);

	if (f_ptr)
	{
		return f_ptr(d);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_gps_stop(nyx_device_handle_t handle)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	CHECK_DEVICE_TYPE(d, NYX_DEVICE_GPS);
	nyx_gps_stop_function_t f_ptr = LOOKUP_METHOD(d, NYX_GPS_STOP_MODULE_METHOD);

	if (f_ptr)
	{
		return f_ptr(d);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_gps_cleanup(nyx_device_handle_t handle)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	CHECK_DEVICE_TYPE(d, NYX_DEVICE_GPS);
	nyx_gps_cleanup_function_t f_ptr = LOOKUP_METHOD(d,
	                                   NYX_GPS_CLEANUP_MODULE_METHOD);

	if (f_ptr)
	{
		return f_ptr(d);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_gps_inject_time(nyx_device_handle_t handle,
                                int64_t time,
                                int64_t timeReference,
                                int uncertainty)
{
	nyx_execute_return_function(gps_inject_time, GPS, INJECT_TIME, handle,
	                            time, timeReference, uncertainty);
}

nyx_error_t nyx_gps_inject_location(nyx_device_handle_t handle,
                                    double latitude,
                                    double longitude,
                                    float accuracy)
{
	nyx_execute_return_function(gps_inject_location, GPS, INJECT_LOCATION, handle,
	                            latitude, longitude, accuracy);
}

nyx_error_t nyx_gps_delete_aiding_data(nyx_device_handle_t handle,
                                       nyx_gps_aiding_data_t flags)
{
	nyx_execute_return_function(gps_delete_aiding_data, GPS, DELETE_AIDING_DATA,
	                            handle, flags);
}

nyx_error_t nyx_gps_set_position_mode(nyx_device_handle_t handle,
                                      nyx_gps_position_mode_t mode,
                                      nyx_gps_position_recurrence_t recurrence,
                                      uint32_t min_interval,
                                      uint32_t preferred_accuracy,
                                      uint32_t preferred_time)
{
	nyx_execute_return_function(gps_set_position_mode, GPS, SET_POSITION_MODE,
	                            handle,
	                            mode, recurrence, min_interval, preferred_accuracy, preferred_time);
}

nyx_error_t nyx_gps_inject_extra_cmd(nyx_device_handle_t handle,
                                     char *cmd,
                                     int length)
{
	nyx_execute_return_function(gps_inject_extra_cmd, GPS, INJECT_EXTRA_CMD, handle,
	                            cmd, length);
}

nyx_error_t nyx_gps_inject_xtra_data(nyx_device_handle_t handle,
                                     char *data,
                                     int length)
{
	nyx_execute_return_function(gps_inject_xtra_data, GPS, INJECT_XTRA_DATA, handle,
	                            data, length);
}

nyx_error_t nyx_gps_data_conn_open(nyx_device_handle_t handle,
                                   nyx_agps_type_t agpsType,
                                   const char *apn,
                                   nyx_agps_bearer_type_t bearerType)
{
	nyx_execute_return_function(gps_data_conn_open, GPS, DATA_CONN_OPEN, handle,
	                            agpsType, apn, bearerType);
}

nyx_error_t nyx_gps_data_conn_closed(nyx_device_handle_t handle,
                                     nyx_agps_type_t agpsType)
{
	nyx_execute_return_function(gps_data_conn_closed, GPS, DATA_CONN_CLOSED, handle,
	                            agpsType);
}

nyx_error_t nyx_gps_data_conn_failed(nyx_device_handle_t handle,
                                     nyx_agps_type_t agpsType)
{
	nyx_execute_return_function(gps_data_conn_failed, GPS, DATA_CONN_FAILED, handle,
	                            agpsType);
}

nyx_error_t nyx_gps_set_server(nyx_device_handle_t handle,
                               nyx_agps_type_t type,
                               const char *hostname,
                               int port)
{
	nyx_execute_return_function(gps_set_server, GPS, SET_SERVER, handle,
	                            type, hostname, port);
}

nyx_error_t nyx_gps_send_ni_response(nyx_device_handle_t handle,
                                     int notif_id,
                                     nyx_gps_ni_user_response_type_t user_response)
{
	nyx_execute_return_function(gps_send_ni_response, GPS, SEND_NI_RESPONSE, handle,
	                            notif_id, user_response);
}

nyx_error_t nyx_gps_set_ref_location(nyx_device_handle_t handle,
                                     const nyx_agps_ref_location_t *agps_reflocation,
                                     size_t sz_struct)
{
	nyx_execute_return_function(gps_set_ref_location, GPS, SET_REF_LOCATION, handle,
	                            agps_reflocation, sz_struct);
}

nyx_error_t nyx_gps_set_set_id(nyx_device_handle_t handle,
                               nyx_agps_set_id_type_t type,
                               const char *set_id)
{
	nyx_execute_return_function(gps_set_set_id, GPS, SET_SET_ID, handle,
	                            type, set_id);
}

nyx_error_t nyx_gps_send_ni_message(nyx_device_handle_t handle,
                                    uint8_t *msg,
                                    size_t len)
{
	nyx_execute_return_function(gps_send_ni_message, GPS, SEND_NI_MESSAGE, handle,
	                            msg, len);
}

nyx_error_t nyx_gps_update_network_state(nyx_device_handle_t handle,
        int connected,
        int type,
        int roaming,
        const char *extra_info)
{
	nyx_execute_return_function(gps_update_network_state, GPS, UPDATE_NETWORK_STATE,
	                            handle,
	                            connected, type, roaming, extra_info);
}

nyx_error_t nyx_gps_update_network_availability(nyx_device_handle_t handle,
        int available,
        const char *apn)
{
	nyx_execute_return_function(gps_update_network_availability, GPS,
	                            UPDATE_NETWORK_AVAILABILITY, handle,
	                            available, apn);
}

nyx_error_t nyx_gps_add_geofence_area(nyx_device_handle_t handle,
                                      int32_t geofence_id,
                                      double latitude,
                                      double longitude,
                                      double radius_meters,
                                      int last_transition,
                                      int monitor_transitions,
                                      int notification_responsiveness_ms,
                                      int unknown_timer_ms)
{
	nyx_execute_return_function(gps_add_geofence_area, GPS, ADD_GEOFENCE_AREA,
	                            handle,
	                            geofence_id, latitude, longitude, radius_meters, last_transition,
	                            monitor_transitions, notification_responsiveness_ms, unknown_timer_ms);
}

nyx_error_t nyx_gps_remove_geofence_area(nyx_device_handle_t handle,
        int32_t geofence_id)
{
	nyx_execute_return_function(gps_remove_geofence_area, GPS, REMOVE_GEOFENCE_AREA,
	                            handle, geofence_id);
}

nyx_error_t nyx_gps_pause_geofence(nyx_device_handle_t handle,
                                   int32_t geofence_id)
{
	nyx_execute_return_function(gps_pause_geofence, GPS, PAUSE_GEOFENCE, handle,
	                            geofence_id);
}

nyx_error_t nyx_gps_resume_geofence(nyx_device_handle_t handle,
                                    int32_t geofence_id,
                                    int monitor_transitions)
{
	nyx_execute_return_function(gps_resume_geofence, GPS, RESUME_GEOFENCE, handle,
	                            geofence_id, monitor_transitions);
}

nyx_error_t nyx_gps_init_xtra_client(nyx_device_handle_t handle,
                                     nyx_gps_xtra_client_config_t *xtra_client_config,
                                     nyx_gps_xtra_client_callbacks_t *xtra_client_cbs)
{
	nyx_execute_return_function(gps_init_xtra_client, GPS, INIT_XTRA_CLIENT, handle,
	                            xtra_client_config, xtra_client_cbs);
}

nyx_error_t nyx_gps_stop_xtra_client(nyx_device_handle_t handle)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	CHECK_DEVICE_TYPE(d, NYX_DEVICE_GPS);
	nyx_gps_stop_xtra_client_function_t f_ptr = LOOKUP_METHOD(d,
	        NYX_GPS_STOP_XTRA_CLIENT_MODULE_METHOD);

	if (f_ptr)
	{
		return f_ptr(d);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_gps_download_xtra_data(nyx_device_handle_t handle)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	CHECK_DEVICE_TYPE(d, NYX_DEVICE_GPS);
	nyx_gps_download_xtra_data_function_t f_ptr = LOOKUP_METHOD(d,
	        NYX_GPS_DOWNLOAD_XTRA_DATA_MODULE_METHOD);

	if (f_ptr)
	{
		return f_ptr(d);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

nyx_error_t nyx_gps_download_ntp_time(nyx_device_handle_t handle)
{
	nyx_device_t *d = (nyx_device_t *)handle;
	CHECK_DEVICE(d);
	CHECK_DEVICE_TYPE(d, NYX_DEVICE_GPS);
	nyx_gps_download_ntp_time_function_t f_ptr = LOOKUP_METHOD(d,
	        NYX_GPS_DOWNLOAD_NTP_TIME_MODULE_METHOD);

	if (f_ptr)
	{
		return f_ptr(d);
	}
	else
	{
		return NYX_ERROR_NOT_IMPLEMENTED;
	}
}

