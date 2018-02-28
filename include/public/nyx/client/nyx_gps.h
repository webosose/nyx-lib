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
 * @file nyx_gps.h
 *
 * @brief Nyx's public gps API.
 *
 */

#ifndef _NYX_GPS_H_
#define _NYX_GPS_H_

#include <nyx/common/nyx_gps_common.h>

#ifdef __cplusplus
extern "C" {
#endif



// Global initialization for GPS
NYX_API_EXPORT nyx_error_t nyx_gps_init(nyx_device_handle_t handle,
                                        nyx_gps_callbacks_t *gps_cbs,
                                        nyx_gps_xtra_callbacks_t *xtra_cbs,
                                        nyx_agps_callbacks_t *agps_cbs,
                                        nyx_gps_ni_callbacks_t *gps_ni_cbs,
                                        nyx_agps_ril_callbacks_t *agps_ril_cbs,
                                        nyx_gps_geofence_callbacks_t *geofence_cbs);



// Standard GPS Interface
NYX_API_EXPORT nyx_error_t nyx_gps_start(nyx_device_handle_t handle);

NYX_API_EXPORT nyx_error_t nyx_gps_stop(nyx_device_handle_t handle);

NYX_API_EXPORT nyx_error_t nyx_gps_cleanup(nyx_device_handle_t handle);

NYX_API_EXPORT nyx_error_t nyx_gps_inject_time(nyx_device_handle_t handle,
        int64_t time,
        int64_t timeReference,
        int uncertainty);

NYX_API_EXPORT nyx_error_t nyx_gps_inject_location(nyx_device_handle_t handle,
        double latitude,
        double longitude,
        float accuracy);

NYX_API_EXPORT nyx_error_t nyx_gps_delete_aiding_data(nyx_device_handle_t
        handle,
        nyx_gps_aiding_data_t flags);

NYX_API_EXPORT nyx_error_t nyx_gps_set_position_mode(nyx_device_handle_t handle,
        nyx_gps_position_mode_t mode,
        nyx_gps_position_recurrence_t recurrence,
        uint32_t min_interval,
        uint32_t preferred_accuracy,
        uint32_t preferred_time);



// Extended interface for extra command support
NYX_API_EXPORT nyx_error_t nyx_gps_inject_extra_cmd(nyx_device_handle_t handle,
        char *cmd,
        int length);



// Extended interface for XTRA support
NYX_API_EXPORT nyx_error_t nyx_gps_inject_xtra_data(nyx_device_handle_t handle,
        char *data,
        int length);



// Extended interface for AGPS support
NYX_API_EXPORT nyx_error_t nyx_gps_data_conn_open(nyx_device_handle_t handle,
        nyx_agps_type_t agpsType,
        const char *apn,
        nyx_agps_bearer_type_t bearerType);

NYX_API_EXPORT nyx_error_t nyx_gps_data_conn_closed(nyx_device_handle_t handle,
        nyx_agps_type_t agpsType);

NYX_API_EXPORT nyx_error_t nyx_gps_data_conn_failed(nyx_device_handle_t handle,
        nyx_agps_type_t agpsType);

NYX_API_EXPORT nyx_error_t nyx_gps_set_server(nyx_device_handle_t handle,
        nyx_agps_type_t type,
        const char *hostname,
        int port);



// Extended interface for Network-initiated (NI) support
NYX_API_EXPORT nyx_error_t nyx_gps_send_ni_response(nyx_device_handle_t handle,
        int notif_id,
        nyx_gps_ni_user_response_type_t user_response);



// Extended interface for AGPS_RIL support
NYX_API_EXPORT nyx_error_t nyx_gps_set_ref_location(nyx_device_handle_t handle,
        const nyx_agps_ref_location_t *agps_reflocation,
        size_t sz_struct);

NYX_API_EXPORT nyx_error_t nyx_gps_set_set_id(nyx_device_handle_t handle,
        nyx_agps_set_id_type_t type,
        const char *set_id);

NYX_API_EXPORT nyx_error_t nyx_gps_send_ni_message(nyx_device_handle_t handle,
        uint8_t *msg,
        size_t len);

NYX_API_EXPORT nyx_error_t nyx_gps_update_network_state(
    nyx_device_handle_t handle,
    int connected,
    int type,
    int roaming,
    const char *extra_info);

NYX_API_EXPORT nyx_error_t nyx_gps_update_network_availability(
    nyx_device_handle_t handle,
    int available,
    const char *apn);



// Extended interface for Geofencing support
NYX_API_EXPORT nyx_error_t nyx_gps_add_geofence_area(nyx_device_handle_t handle,
        int32_t geofence_id,
        double latitude,
        double longitude,
        double radius_meters,
        int last_transition,
        int monitor_transitions,
        int notification_responsiveness_ms,
        int unknown_timer_ms);

NYX_API_EXPORT nyx_error_t nyx_gps_remove_geofence_area(
    nyx_device_handle_t handle,
    int32_t geofence_id);

NYX_API_EXPORT nyx_error_t nyx_gps_pause_geofence(nyx_device_handle_t handle,
        int32_t geofence_id);

NYX_API_EXPORT nyx_error_t nyx_gps_resume_geofence(nyx_device_handle_t handle,
        int32_t geofence_id,
        int monitor_transitions);



// XTRA client support
NYX_API_EXPORT nyx_error_t nyx_gps_init_xtra_client(nyx_device_handle_t handle,
        nyx_gps_xtra_client_config_t *xtra_client_config,
        nyx_gps_xtra_client_callbacks_t *xtra_client_cbs);

NYX_API_EXPORT nyx_error_t nyx_gps_stop_xtra_client(nyx_device_handle_t handle);

NYX_API_EXPORT nyx_error_t nyx_gps_download_xtra_data(nyx_device_handle_t
        handle);

NYX_API_EXPORT nyx_error_t nyx_gps_download_ntp_time(nyx_device_handle_t
        handle);



#ifdef __cplusplus
}
#endif

#endif /* _NYX_GPS_H_ */
