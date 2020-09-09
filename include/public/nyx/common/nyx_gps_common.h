// Copyright (c) 2012-2020 LG Electronics, Inc.
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

#ifndef _NYX_GPS_COMMON_H_
#define _NYX_GPS_COMMON_H_

#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/types.h>
#include <pthread.h>

__BEGIN_DECLS



/** Maximum number of satellites in view */
#define NYX_GPS_MAX_SVS 32

/** Requested operational mode for GPS operation. */
typedef uint32_t nyx_gps_position_mode_t;
/** Mode for running GPS standalone (no assistance). */
#define NYX_GPS_POSITION_MODE_STANDALONE    0
/** AGPS MS-Based mode. */
#define NYX_GPS_POSITION_MODE_MS_BASED      1
/** AGPS MS-Assisted mode. */
#define NYX_GPS_POSITION_MODE_MS_ASSISTED   2

/** Requested recurrence mode for GPS operation. */
typedef uint32_t nyx_gps_position_recurrence_t;
/** Receive GPS fixes on a recurring basis at a specified period. */
#define NYX_GPS_POSITION_RECURRENCE_PERIODIC    0
/** Request a single shot GPS fix. */
#define NYX_GPS_POSITION_RECURRENCE_SINGLE      1

/** GPS status event values. */
typedef uint16_t nyx_gps_status_value_t;
/** GPS status unknown. */
#define NYX_GPS_STATUS_NONE             0
/** GPS has begun navigating. */
#define NYX_GPS_STATUS_SESSION_BEGIN    1
/** GPS has stopped navigating. */
#define NYX_GPS_STATUS_SESSION_END      2
/** GPS has powered on but is not navigating. */
#define NYX_GPS_STATUS_ENGINE_ON        3
/** GPS is powered off. */
#define NYX_GPS_STATUS_ENGINE_OFF       4

/** Flags to indicate which values are valid in a GpsLocation. */
typedef uint16_t nyx_gps_location_flags_t;
/** nyx_gps_location_t has valid latitude and longitude. */
#define NYX_GPS_LOCATION_HAS_LAT_LONG   0x0001
/** nyx_gps_location_t has valid altitude. */
#define NYX_GPS_LOCATION_HAS_ALTITUDE   0x0002
/** nyx_gps_location_t has valid speed. */
#define NYX_GPS_LOCATION_HAS_SPEED      0x0004
/** nyx_gps_location_t has valid bearing. */
#define NYX_GPS_LOCATION_HAS_BEARING    0x0008
/** nyx_gps_location_t has valid horizontal accuracy. */
#define NYX_GPS_LOCATION_HAS_ACCURACY   0x0010
/** nyx_gps_location_t has valid vertical accuracy. */
#define NYX_GPS_LOCATION_HAS_VERTICAL_ACCURACY   0x0020

/** Flags for the nyx_gps_set_capabilities callback. */

/** GPS HAL schedules fixes for NYX_GPS_POSITION_RECURRENCE_PERIODIC mode.
    If this is not set, then the framework will use 1000ms for min_interval
    and will start and call start() and stop() to schedule the GPS.
 */
#define NYX_GPS_CAPABILITY_SCHEDULING       0x0000001
/** GPS supports MS-Based AGPS mode */
#define NYX_GPS_CAPABILITY_MSB              0x0000002
/** GPS supports MS-Assisted AGPS mode */
#define NYX_GPS_CAPABILITY_MSA              0x0000004
/** GPS supports single-shot fixes */
#define NYX_GPS_CAPABILITY_SINGLE_SHOT      0x0000008
/** GPS supports on demand time injection */
#define NYX_GPS_CAPABILITY_ON_DEMAND_TIME   0x0000010
/** Hybrid support, the webOS Framework will query to see if this capability is set before using the ulp functionalities in HAL */
#define NYX_ULP_CAPABILITY                  0x0000020


/** Flags used to specify which aiding data to delete
    when calling delete_aiding_data(). */
typedef uint32_t nyx_gps_aiding_data_t;
#define NYX_GPS_DELETE_EPHEMERIS                     0x00000001
#define NYX_GPS_DELETE_ALMANAC                       0x00000002
#define NYX_GPS_DELETE_POSITION                      0x00000004
#define NYX_GPS_DELETE_TIME                          0x00000008
#define NYX_GPS_DELETE_IONO                          0x00000010
#define NYX_GPS_DELETE_UTC                           0x00000020
#define NYX_GPS_DELETE_HEALTH                        0x00000040
#define NYX_GPS_DELETE_SVDIR                         0x00000080
#define NYX_GPS_DELETE_SVSTEER                       0x00000100
#define NYX_GPS_DELETE_SADATA                        0x00000200
#define NYX_GPS_DELETE_RTI                           0x00000400
#define NYX_GPS_DELETE_CELLDB_INFO                   0x00000800
#define NYX_GPS_DELETE_ALMANAC_CORR                  0x00001000
#define NYX_GPS_DELETE_FREQ_BIAS_EST                 0x00002000
#define NYX_GPS_DELETE_EPHEMERIS_GLO                 0x00004000
#define NYX_GPS_DELETE_ALMANAC_GLO                   0x00008000
#define NYX_GPS_DELETE_SVDIR_GLO                     0x00010000
#define NYX_GPS_DELETE_SVSTEER_GLO                   0x00020000
#define NYX_GPS_DELETE_ALMANAC_CORR_GLO              0x00040000
#define NYX_GPS_DELETE_TIME_GPS                      0x00080000
#define NYX_GPS_DELETE_TIME_GLO                      0x00100000
#define NYX_GLO_DELETE_EPHEMERIS                     0x00004000
#define NYX_GLO_DELETE_ALMANAC                       0x00008000
#define NYX_GLO_DELETE_SVDIR                         0x00010000
#define NYX_GLO_DELETE_SVSTEER                       0x00020000
#define NYX_GLO_DELETE_ALMANAC_CORR                  0x00040000
#define NYX_GLO_DELETE_TIME_GPS                      0x00080000
#define NYX_GLO_DELETE_TIME                          0x00100000
#define NYX_BDS_DELETE_SVDIR                         0X00200000
#define NYX_BDS_DELETE_SVSTEER                       0X00400000
#define NYX_BDS_DELETE_TIME                          0X00800000
#define NYX_BDS_DELETE_ALMANAC_CORR                  0X01000000
#define NYX_BDS_DELETE_EPHEMERIS                     0X02000000
#define NYX_BDS_DELETE_ALMANAC                       0X04000000

#define NYX_GPS_DELETE_ALL                           0xFFFFFFFF

/** AGPS type */
typedef int16_t nyx_agps_type_t;
#define NYX_AGPS_TYPE_INVALID       -1
#define NYX_AGPS_TYPE_ANY           0
#define NYX_AGPS_TYPE_SUPL          1
#define NYX_AGPS_TYPE_C2K           2
#define NYX_AGPS_TYPE_WWAN_ANY      3
#define NYX_AGPS_TYPE_WIFI          4

/** SSID length */
#define NYX_SSID_BUF_SIZE (32+1)

typedef uint16_t nyx_agps_set_id_type_t;
#define NYX_AGPS_SET_ID_TYPE_NONE    0
#define NYX_AGPS_SET_ID_TYPE_IMSI    1
#define NYX_AGPS_SET_ID_TYPE_MSISDN  2

typedef int16_t nyx_agps_bearer_type_t;
#define NYX_AGPS_APN_BEARER_INVALID    -1
#define NYX_AGPS_APN_BEARER_IPV4        0
#define NYX_AGPS_APN_BEARER_IPV6        1
#define NYX_AGPS_APN_BEARER_IPV4V6      2

/**
 * String length constants
 */
#define NYX_GPS_NI_SHORT_STRING_MAXLEN      256
#define NYX_GPS_NI_LONG_STRING_MAXLEN       2048

/**
 * nyx_gps_ni_type_t constants
 */
typedef uint32_t nyx_gps_ni_type_t;
#define NYX_GPS_NI_TYPE_VOICE              1
#define NYX_GPS_NI_TYPE_UMTS_SUPL          2
#define NYX_GPS_NI_TYPE_UMTS_CTRL_PLANE    3

/**
 * nyx_gps_ni_notify_flags_t constants
 */
typedef uint32_t nyx_gps_ni_notify_flags_t;
/** NI requires notification */
#define NYX_GPS_NI_NEED_NOTIFY          0x0001
/** NI requires verification */
#define NYX_GPS_NI_NEED_VERIFY          0x0002
/** NI requires privacy override, no notification/minimal trace */
#define NYX_GPS_NI_PRIVACY_OVERRIDE     0x0004

/**
 * GPS NI responses, used to define the response in
 * NI structures
 */
typedef int nyx_gps_ni_user_response_type_t;
#define NYX_GPS_NI_USER_RESPONSE_ACCEPT         1
#define NYX_GPS_NI_USER_RESPONSE_DENY           2
#define NYX_GPS_NI_USER_RESPONSE_NORESP         3

/**
 * NI data encoding scheme
 */
typedef int nyx_gps_ni_encoding_type_t;
#define NYX_GPS_NI_ENC_NONE                   0
#define NYX_GPS_NI_ENC_SUPL_GSM_DEFAULT       1
#define NYX_GPS_NI_ENC_SUPL_UTF8              2
#define NYX_GPS_NI_ENC_SUPL_UCS2              3
#define NYX_GPS_NI_ENC_UNKNOWN                -1

/** AGPS status event values. */
typedef uint16_t nyx_agps_status_value_t;
/** GPS requests data connection for AGPS. */
#define NYX_AGPS_REQUEST_DATA_CONN  1
/** GPS releases the AGPS data connection. */
#define NYX_AGPS_RELEASE_DATA_CONN  2
/** AGPS data connection initiated */
#define NYX_AGPS_DATA_CONNECTED     3
/** AGPS data connection completed */
#define NYX_AGPS_DATA_CONN_DONE     4
/** AGPS data connection failed */
#define NYX_AGPS_DATA_CONN_FAILED   5

#define NYX_AGPS_REF_LOCATION_TYPE_GSM_CELLID   1
#define NYX_AGPS_REF_LOCATION_TYPE_UMTS_CELLID  2
#define NYX_AGPS_REG_LOCATION_TYPE_MAC          3

/** Network types for update_network_state "type" parameter */
#define NYX_AGPS_RIL_NETWORK_TYPE_MOBILE        0
#define NYX_AGPS_RIL_NETWORK_TYPE_WIFI          1
#define NYX_AGPS_RIL_NETWORK_TYPE_MOBILE_MMS    2
#define NYX_AGPS_RIL_NETWORK_TYPE_MOBILE_SUPL   3
#define NYX_AGPS_RIL_NETWORK_TTYPE_MOBILE_DUN   4
#define NYX_AGPS_RIL_NETWORK_TTYPE_MOBILE_HIPRI 5
#define NYX_AGPS_RIL_NETWORK_TTYPE_WIMAX        6

#define NYX_AGPS_RIL_REQUEST_SETID_IMSI     (1<<0L)
#define NYX_AGPS_RIL_REQUEST_SETID_MSISDN   (1<<1L)

#define NYX_AGPS_RIL_REQUEST_REFLOC_CELLID  (1<<0L)
#define NYX_AGPS_RIL_REQUEST_REFLOC_MAC     (1<<1L)

#define NYX_GEOFENCER_ENTERED     (1<<0L)
#define NYX_GEOFENCER_EXITED      (1<<1L)
#define NYX_GEOFENCER_UNCERTAIN   (1<<2L)

#define NYX_GEOFENCER_UNAVAILABLE (1<<0L)
#define NYX_GEOFENCER_AVAILABLE   (1<<1L)

#define NYX_GEOFENCER_OPERATION_SUCCESS           0
#define NYX_GEOFENCER_ERROR_TOO_MANY_GEOFENCES -100
#define NYX_GEOFENCER_ERROR_ID_EXISTS          -101
#define NYX_GEOFENCER_ERROR_ID_UNKNOWN         -102
#define NYX_GEOFENCER_ERROR_INVALID_TRANSITION -103
#define NYX_GEOFENCER_ERROR_GENERIC            -149

#define NYX_GPS_XTRA_CLIENT_MAX_URL_LEN            256
#define NYX_GPS_XTRA_CLIENT_NUMBER_OF_SNTP_SERVERS 3
#define NYX_GPS_XTRA_CLIENT_NUMBER_OF_XTRA_SERVERS 3
#define NYX_GPS_XTRA_CLIENT_USER_AGENT_STRING_LEN  256

/** Xtra URL type **/
typedef char nyx_gps_xtra_client_url_type[NYX_GPS_XTRA_CLIENT_MAX_URL_LEN];


/* GPS providers for nyx-cmd*/
typedef enum
{
        NYX_GPS_PROVIDER_NAME,
        NYX_GPS_PROVIDER_STATUS,
} nyx_gps_providers_query_t;

/** Represents a location. */
typedef struct
{
	/** set to sizeof(nyx_gps_location_t) */
	size_t                      size;
	/** Contains nyx_gps_location_flags_t bits. */
	nyx_gps_location_flags_t    flags;
	/** Represents latitude in degrees. */
	double                      latitude;
	/** Represents longitude in degrees. */
	double                      longitude;
	/** Represents altitude in meters above the WGS 84 reference
	 * ellipsoid. */
	double                      altitude;
	/** Represents speed in meters per second. */
	float                       speed;
	/** Represents heading in degrees. */
	float                       bearing;
	/** Represents expected accuracy in meters. */
	float                       accuracy;
	/** Represents expected vertical accuracy in meters. */
	float                       vertical_accuracy;
	/** Timestamp for the location fix. */
	int64_t                     timestamp;
} nyx_gps_location_t;

/** Represents the status. */
typedef struct
{
	/** set to sizeof(nyx_gps_status_t) */
	size_t                    size;
	nyx_gps_status_value_t    status;
} nyx_gps_status_t;

/** Represents SV information. */
typedef struct
{
	/** set to sizeof(nyx_gps_sv_info_t) */
	size_t          size;
	/** Pseudo-random number for the SV. */
	int             prn;
	/** Signal to noise ratio. */
	float           snr;
	/** Elevation of SV in degrees. */
	float           elevation;
	/** Azimuth of SV in degrees. */
	float           azimuth;
} nyx_gps_sv_info_t;

/** Represents SV status. */
typedef struct
{
	/** set to sizeof(nyx_gps_sv_status_t) */
	size_t              size;

	/** Number of SVs currently visible. */
	int                 num_svs;

	/** Contains an array of SV information. */
	nyx_gps_sv_info_t   sv_list[NYX_GPS_MAX_SVS];

	/** Represents a bit mask indicating which SVs
	 * have ephemeris data.
	 */
	uint32_t            ephemeris_mask;

	/** Represents a bit mask indicating which SVs
	 * have almanac data.
	 */
	uint32_t            almanac_mask;

	/**
	 * Represents a bit mask indicating which SVs
	 * were used for computing the most recent position fix.
	 */
	uint32_t            used_in_fix_mask;
} nyx_gps_sv_status_t;

/* 2G and 3G */
/* In 3G lac is discarded */
typedef struct
{
	uint16_t type;
	uint16_t mcc;
	uint16_t mnc;
	uint16_t lac;
	uint32_t cid;
} nyx_agps_ref_location_cellid_t;

typedef struct
{
	uint8_t mac[6];
} nyx_agps_ref_location_mac_t;

/** Represents ref locations */
typedef struct
{
	uint16_t type;
	union
	{
		nyx_agps_ref_location_cellid_t  cellID;
		nyx_agps_ref_location_mac_t     mac;
	} u;
} nyx_agps_ref_location_t;

/** Represents the status of AGPS. */
typedef struct
{
	/** set to sizeof(nyx_agps_status_t) */
	size_t                  size;

	nyx_agps_type_t         type;
	nyx_agps_status_value_t status;
	int                     ipv4_addr;
	char                    ipv6_addr[16];
	char                    ssid[NYX_SSID_BUF_SIZE];
	char                    password[NYX_SSID_BUF_SIZE];
} nyx_agps_status_t;

/** Represents an NI request */
typedef struct
{
	/** set to sizeof(nyx_gps_ni_notification_t) */
	size_t                          size;

	/**
	 * An ID generated by HAL to associate NI notifications and UI
	 * responses
	 */
	int                             notification_id;

	/**
	 * An NI type used to distinguish different categories of NI
	 * events, such as GPS_NI_TYPE_VOICE, GPS_NI_TYPE_UMTS_SUPL, ...
	 */
	nyx_gps_ni_type_t               ni_type;

	/**
	 * Notification/verification options, combinations of GpsNiNotifyFlags constants
	 */
	nyx_gps_ni_notify_flags_t       notify_flags;

	/**
	 * Timeout period to wait for user response.
	 * Set to 0 for no time out limit.
	 */
	int                             timeout;

	/**
	 * Default response when time out.
	 */
	nyx_gps_ni_user_response_type_t default_response;

	/**
	 * Requestor ID
	 */
	char                            requestor_id[NYX_GPS_NI_SHORT_STRING_MAXLEN];

	/**
	 * Notification message. It can also be used to store client_id in some cases
	 */
	char                            text[NYX_GPS_NI_LONG_STRING_MAXLEN];

	/**
	 * Client name decoding scheme
	 */
	nyx_gps_ni_encoding_type_t      requestor_id_encoding;

	/**
	 * Client name decoding scheme
	 */
	nyx_gps_ni_encoding_type_t      text_encoding;

	/**
	 * A pointer to extra data. Format:
	 * key_1 = value_1
	 * key_2 = value_2
	 */
	char                            extras[NYX_GPS_NI_LONG_STRING_MAXLEN];

} nyx_gps_ni_notification_t;

/** XTRA client Configuration **/
typedef struct
{
	nyx_gps_xtra_client_url_type
	sntp_server_url[NYX_GPS_XTRA_CLIENT_NUMBER_OF_SNTP_SERVERS];
	nyx_gps_xtra_client_url_type
	xtra_server_url[NYX_GPS_XTRA_CLIENT_NUMBER_OF_XTRA_SERVERS];
	char
	user_agent_string[NYX_GPS_XTRA_CLIENT_USER_AGENT_STRING_LEN];
} nyx_gps_xtra_client_config_t;





/** Nyx GPS callbacks structure */
typedef void (* nyx_gps_location_callback)(nyx_gps_location_t *location,
        void *user_data);

typedef void (* nyx_gps_status_callback)(nyx_gps_status_t *status,
        void *user_data);

typedef void (* nyx_gps_sv_status_callback)(nyx_gps_sv_status_t *sv_info,
        void *user_data);

typedef void (* nyx_gps_nmea_callback)(int64_t timestamp, const char *nmea,
                                       int length, void *user_data);

typedef void (* nyx_gps_set_capabilities_callback)(uint32_t capabilities,
        void *user_data);

typedef void (* nyx_gps_acquire_wakelock_callback)(void *user_data);

typedef void (* nyx_gps_release_wakelock_callback)(void *user_data);

typedef void (* nyx_gps_request_utc_time_callback)(void *user_data);

typedef struct
{
	void                                   *user_data;
	nyx_gps_location_callback               location_cb;
	nyx_gps_status_callback                 status_cb;
	nyx_gps_sv_status_callback              sv_status_cb;
	nyx_gps_nmea_callback                   nmea_cb;
	nyx_gps_set_capabilities_callback       set_capabilities_cb;
	nyx_gps_acquire_wakelock_callback       acquire_wakelock_cb;
	nyx_gps_release_wakelock_callback       release_wakelock_cb;
	nyx_gps_request_utc_time_callback       request_utc_time_cb;
} nyx_gps_callbacks_t;



/** Nyx GPS Xtra callbacks structure */
typedef void (* nyx_gps_xtra_download_request_callback)(void *user_data);

typedef struct
{
	void                                   *user_data;
	nyx_gps_xtra_download_request_callback  xtra_download_request_cb;
} nyx_gps_xtra_callbacks_t;



/** Nyx A-GPS callbacks structure */
typedef void (* nyx_agps_status_callback)(nyx_agps_status_t *status,
        void *user_data);

typedef struct
{
	void                                   *user_data;
	nyx_agps_status_callback                status_cb;
} nyx_agps_callbacks_t;



/** Nyx GPS NI callbacks structure */
typedef void (* nyx_gps_ni_notify_callback)(nyx_gps_ni_notification_t
        *notification, void *user_data);

typedef struct
{
	void                                   *user_data;
	nyx_gps_ni_notify_callback              ni_notify_cb;
} nyx_gps_ni_callbacks_t;



/** Nyx A-GPS RIL callbacks structure */
typedef void (* nyx_agps_ril_request_set_id_callback)(uint32_t flags,
        void *user_data);

typedef void (* nyx_agps_ril_request_ref_loc_callback)(uint32_t flags,
        void *user_data);

typedef struct
{
	void                                   *user_data;
	nyx_agps_ril_request_set_id_callback    ril_request_set_id_cb;
	nyx_agps_ril_request_ref_loc_callback   ril_request_ref_loc_cb;
} nyx_agps_ril_callbacks_t;



/** Nyx GPS Geofence callbacks structure */
typedef void (* nyx_gps_geofence_transition_callback)(int32_t geofence_id,
        nyx_gps_location_t *location,
        int32_t transition,
        int64_t timestamp,
        void *user_data);

typedef void (* nyx_gps_geofence_status_callback)(int32_t status,
        nyx_gps_location_t *last_location,
        void *user_data);

typedef void (* nyx_gps_geofence_add_callback)(int32_t geofence_id,
        int32_t status, void *user_data);

typedef void (* nyx_gps_geofence_remove_callback)(int32_t geofence_id,
        int32_t status, void *user_data);

typedef void (* nyx_gps_geofence_pause_callback)(int32_t geofence_id,
        int32_t status, void *user_data);

typedef void (* nyx_gps_geofence_resume_callback)(int32_t geofence_id,
        int32_t status, void *user_data);

typedef struct
{
	void                                   *user_data;
	nyx_gps_geofence_transition_callback    geofence_transition_cb;
	nyx_gps_geofence_status_callback        geofence_status_cb;
	nyx_gps_geofence_add_callback           geofence_add_cb;
	nyx_gps_geofence_remove_callback        geofence_remove_cb;
	nyx_gps_geofence_pause_callback         geofence_pause_cb;
	nyx_gps_geofence_resume_callback        geofence_resume_cb;
} nyx_gps_geofence_callbacks_t;



/** Nyx GPS Xtra Client callbacks structure. */
typedef void (* nyx_gps_xtra_client_data_callback)(char *data,
        int length,
        void *user_data);

typedef void (* nyx_gps_xtra_client_time_callback)(int64_t utc_time,
        int64_t time_reference,
        int uncertainty,
        void *user_data);

typedef struct
{
	void                                   *user_data;
	nyx_gps_xtra_client_data_callback       xtra_client_data_cb;
	nyx_gps_xtra_client_time_callback       xtra_client_time_cb;
} nyx_gps_xtra_client_callbacks_t;



__END_DECLS

#endif /* _NYX_GPS_COMMON_H_ */

