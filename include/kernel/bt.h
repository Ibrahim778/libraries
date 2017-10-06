#ifndef _PSP2_KERNEL_BT_H_
#define _PSP2_KERNEL_BT_H_

#include <psp2/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum SceBtErrorCode {
	SCE_BT_ERROR_REG_NOT_READY                                  	 = 0x802f0101,
	SCE_BT_ERROR_REG_DELETE_NO_ENTRY                            	 = 0x802f0102,
	SCE_BT_ERROR_REG_UPDATE_CANNOT_SAVE                         	 = 0x802f0103,
	SCE_BT_ERROR_REG_SET_HID_DESC_BAD_ARG                       	 = 0x802f0105,
	SCE_BT_ERROR_REG_SET_HID_DESC_NO_REG                        	 = 0x802f0106,
	SCE_BT_ERROR_REG_GET_HID_DESC_NO_REG                        	 = 0x802f0107,
	SCE_BT_ERROR_REG_GET_HID_DESC_TOO_SHORT                     	 = 0x802f0108,
	SCE_BT_ERROR_REG_DELETE_CONNECTING                          	 = 0x802f0109,
	SCE_BT_ERROR_REG_CANNOT_LOAD                                	 = 0x802f010a,
	SCE_BT_ERROR_REG_CANNOT_OPEN                                	 = 0x802f010b,
	SCE_BT_ERROR_REG_CANNOT_READ                                	 = 0x802f010c,
	SCE_BT_ERROR_REG_CANNOT_WRITE                               	 = 0x802f010d,
	SCE_BT_ERROR_INQUIRY_START_BUSY                             	 = 0x802f0201,
	SCE_BT_ERROR_CONNECT_START_NO_REG                           	 = 0x802f0202,
	SCE_BT_ERROR_CONNECT_START_NOT_CONNECTABLE                  	 = 0x802f0203,
	SCE_BT_ERROR_CONNECT_START_BUSY                             	 = 0x802f0204,
	SCE_BT_ERROR_DISCONNECT_START_NOT_CONNECTED                 	 = 0x802f0205,
	SCE_BT_ERROR_PIN_INVALID_LENGTH                             	 = 0x802f0206,
	SCE_BT_ERROR_USER_CONFIRM_NOT_CONNECTED                     	 = 0x802f0207,
	SCE_BT_ERROR_SDP_OPEN_NO_L2C                                	 = 0x802f0208,
	SCE_BT_ERROR_CONNECT_START_REG_FULL                         	 = 0x802f0209,
	SCE_BT_ERROR_CONNECT_START_CONNECTED                        	 = 0x802f020a,
	SCE_BT_ERROR_CONNECT_START_TOO_MANY                         	 = 0x802f020d,
	SCE_BT_ERROR_CONNECT_START_DELETING                         	 = 0x802f020e,
	SCE_BT_ERROR_AVDTP_OPEN_NO_L2C                              	 = 0x802f0501,
	SCE_BT_ERROR_AVDTP_CLOSE_BAD_SERV                           	 = 0x802f0502,
	SCE_BT_ERROR_AVDTP_CLOSE_BAD_STATE                          	 = 0x802f0503,
	SCE_BT_ERROR_AVDTP_START_BAD_SERV                           	 = 0x802f0504,
	SCE_BT_ERROR_AVDTP_START_BAD_STATE                          	 = 0x802f0505,
	SCE_BT_ERROR_AVDTP_STOP_BAD_SERV                            	 = 0x802f0506,
	SCE_BT_ERROR_AVDTP_STOP_BAD_STATE                           	 = 0x802f0507,
	SCE_BT_ERROR_AVDTP_SEND_BAD_STATE                           	 = 0x802f0508,
	SCE_BT_ERROR_AVDTP_RECONF_BAD_SERV                          	 = 0x802f0509,
	SCE_BT_ERROR_AVDTP_RECONF_BAD_STATE                         	 = 0x802f050a,
	SCE_BT_ERROR_AVCTP_OPEN_NO_L2C                              	 = 0x802f0601,
	SCE_BT_ERROR_AVCTP_SEND_NO_L2C                              	 = 0x802f0603,
	SCE_BT_ERROR_AVCTP_NOT_CONNECTED                            	 = 0x802f0604,
	SCE_BT_ERROR_AVCTP_SEND_BUSY                                	 = 0x802f0605,
	SCE_BT_ERROR_AVCTP_SEND_NO_PRESS                            	 = 0x802f0606,
	SCE_BT_ERROR_AVCTP_SEND_NO_RELEASE                          	 = 0x802f0607,
	SCE_BT_ERROR_AVCTP_READ_NO_VOLUME                           	 = 0x802f0608,
	SCE_BT_ERROR_AVCTP_SEND_NOT_RUBY                            	 = 0x802f0609,
	SCE_BT_ERROR_HID_OPEN_NO_L2C                                	 = 0x802f0901,
	SCE_BT_ERROR_HID_CLOSE_NO_L2C                               	 = 0x802f0902,
	SCE_BT_ERROR_HID_SEND_NO_L2C                                	 = 0x802f0903,
	SCE_BT_ERROR_HID_NOT_CONNECTED                              	 = 0x802f0904,
	SCE_BT_ERROR_HID_NO_CAP                                     	 = 0x802f0905,
	SCE_BT_ERROR_HID_INVALID_REQUEST_TYPE                       	 = 0x802f0906,
	SCE_BT_ERROR_HID_INVALID_BUFFER_ADDRESS                     	 = 0x802f0907,
	SCE_BT_ERROR_HID_INVALID_PROTOCOL                           	 = 0x802f0908,
	SCE_BT_ERROR_HID_INVALID_IDLE                               	 = 0x802f0909,
	SCE_BT_ERROR_HID_NOT_YET                                    	 = 0x802f090c,
	SCE_BT_ERROR_HID_INVALID_LENGTH                             	 = 0x802f090d,	
	SCE_BT_ERROR_HID_INVALID_REPORT_ID                          	 = 0x802f090e,
	SCE_BT_ERROR_HID_OVERWRITE_REQ                              	 = 0x802f090f,
	SCE_BT_ERROR_JUMBO_UNLOCK_NOT_OWNER                         	 = 0x802f0b01,
	SCE_BT_ERROR_HCI_TX_OVERFLOW                                	 = 0x802f0b02,
	SCE_BT_ERROR_ACL_TX_BUF_OVERFLOW                            	 = 0x802f0b03,
	SCE_BT_ERROR_ACL_TX_CB_OVERFLOW                             	 = 0x802f0b04,
	SCE_BT_ERROR_TIMER_CANCEL_BAD_ID                            	 = 0x802f0b05,
	SCE_BT_ERROR_TIMER_CANCEL_NOT_INITIALIZED                   	 = 0x802f0b06,
	SCE_BT_ERROR_TIMER_SET_NOT_INITIALIZED                      	 = 0x802f0b07,
	SCE_BT_ERROR_TIMER_SET_NO_SPACE                             	 = 0x802f0b08,
	SCE_BT_ERROR_COPYIN_FAILED                                  	 = 0x802f0b09,
	SCE_BT_ERROR_COPYOUT_FAILED                                 	 = 0x802f0b0a,
	SCE_BT_ERROR_GET_NAME_NO_DEVICE                             	 = 0x802f0c01,
	SCE_BT_ERROR_CB_TOO_MANY                                    	 = 0x802f0c02,
	SCE_BT_ERROR_CB_NOT_REGISTERED                              	 = 0x802f0c03,
	SCE_BT_ERROR_CB_OVERFLOW                                    	 = 0x802f0c04,
	SCE_BT_ERROR_AUDIO_START_NOT_CONNECTED                      	 = 0x802f0d01,
	SCE_BT_ERROR_AUDIO_START_NO_CAP                             	 = 0x802f0d02,
	SCE_BT_ERROR_AUDIO_STOP_NOT_CONNECTED                       	 = 0x802f0d03,
	SCE_BT_ERROR_AUDIO_STOP_NO_CAP                              	 = 0x802f0d04,
	SCE_BT_ERROR_AUDIO_SEND_NOT_CONNECTED                       	 = 0x802f0d05,
	SCE_BT_ERROR_AUDIO_SEND_NOT_STARTED                         	 = 0x802f0d06,
	SCE_BT_ERROR_AUDIO_SEND_INVALID_LENGTH                      	 = 0x802f0d07,
	SCE_BT_ERROR_AUDIO_RECV_NOT_CONNECTED                       	 = 0x802f0d08,
	SCE_BT_ERROR_AUDIO_RECV_NOT_STARTED                         	 = 0x802f0d09,
	SCE_BT_ERROR_AUDIO_RECV_INVALID_LENGTH                      	 = 0x802f0d0a,
	SCE_BT_ERROR_AUDIO_START_INVALID_SERV                       	 = 0x802f0d0b,
	SCE_BT_ERROR_AUDIO_STOP_INVALID_SERV                        	 = 0x802f0d0c,
	SCE_BT_ERROR_AUDIO_START_SERV_FAILED                        	 = 0x802f0d0d,
	SCE_BT_ERROR_AUDIO_STOP_SERV_FAILED                         	 = 0x802f0d0e,
	SCE_BT_ERROR_AUDIO_FREQ_NOT_CONNECTED                       	 = 0x802f0d0f,
	SCE_BT_ERROR_AUDIO_SEND_NO_CP                               	 = 0x802f0d10,
	SCE_BT_ERROR_AUDIO_SEND_BAD_TYPE                            	 = 0x802f0d11,
	SCE_BT_ERROR_AUDIO_RECV_BAD_TYPE                            	 = 0x802f0d12,
	SCE_BT_ERROR_AUDIO_COMBI_NOT_FOUND                          	 = 0x802f0d16,
	SCE_BT_ERROR_AUDIO_SEND_NO_L2C                              	 = 0x802f0d17,
	SCE_BT_ERROR_AUDIO_INTERNAL_1                               	 = 0x802f0d18,
	SCE_BT_ERROR_AUDIO_SEND_BUSY                                	 = 0x802f0d19,
	SCE_BT_ERROR_AUDIO_RECV_BUSY                                	 = 0x802f0d1a,
	SCE_BT_ERROR_AUDIO_SEND_NO_CAP                              	 = 0x802f0d1b,
	SCE_BT_ERROR_AUDIO_SEND_SERV_FAILED                         	 = 0x802f0d1c,
	SCE_BT_ERROR_AUDIO_RECV_NO_CAP                              	 = 0x802f0d1d,
	SCE_BT_ERROR_AUDIO_RECV_SERV_FAILED                         	 = 0x802f0d1e,
	SCE_BT_ERROR_HID_RECV_NOT_CONNECTED                         	 = 0x802f0e01,
	SCE_BT_ERROR_HID_RECV_INVALID_LENGTH                        	 = 0x802f0e02,
	SCE_BT_ERROR_AVRCP_TOO_LONG_TITLE                           	 = 0x802f1201,
	SCE_BT_ERROR_AVRCP_INVALID_PLAY_STATUS                      	 = 0x802f1202,
	SCE_BT_ERROR_CONF_NOT_READY                                 	 = 0x802f1501,
	SCE_BT_ERROR_CONF_INVALID_VALUE                             	 = 0x802f1502,
	SCE_BT_ERROR_CONF_BT_INACTIVE                               	 = 0x802f1503,
	SCE_BT_ERROR_CONF_TIMEOUT                                   	 = 0x802f1504,
	SCE_BT_ERROR_CONF_CARD_NOT_FOUND                            	 = 0x802f1505,
	SCE_BT_ERROR_CONF_FUNCTION_NOT_FOUND                        	 = 0x802f1506,
	SCE_BT_ERROR_CONF_CANT_ENABLE_FUNCTION                      	 = 0x802f1507,
	SCE_BT_ERROR_CONF_CANT_DISABLE_FUNCTION                     	 = 0x802f1508,
	SCE_BT_ERROR_CONF_REGISTER_SUBINTR_HANDLER                  	 = 0x802f1509,
	SCE_BT_ERROR_CONF_RELEASE_SUBINTR_HANDLER                   	 = 0x802f150a,
	SCE_BT_ERROR_CONF_ENABLE_SUBINTR                            	 = 0x802f150b,
	SCE_BT_ERROR_CONF_DISABLE_SUBINTR                           	 = 0x802f150c,
	SCE_BT_ERROR_CONF_ON_TIMEOUT                                	 = 0x802f150d,
	SCE_BT_ERROR_CONF_OFF_TIMEOUT                               	 = 0x802f150e,
	SCE_BT_ERROR_CONF_SUSPEND_TIMEOUT                           	 = 0x802f150f,
	SCE_BT_ERROR_CONF_CANT_ENTER                                	 = 0x802f1520,
	SCE_BT_ERROR_NOTIMP                                         	 = 0x802f2001,
	SCE_BT_ERROR_KPROC_CREATE                                   	 = 0x802f2002,
	SCE_BT_ERROR_SDIO_GET_FUNCTION                              	 = 0x802f2003,
	SCE_BT_ERROR_SDIO_REGISTER_INTR_HANDLER                     	 = 0x802f2004,
	SCE_BT_ERROR_SDIO_UNREGISTER_INTR_HANDLER                   	 = 0x802f2005,
	SCE_BT_ERROR_SDIO_LOCK                                      	 = 0x802f2006,
	SCE_BT_ERROR_SDIO_UNLOCK                                    	 = 0x802f2007,
	SCE_BT_ERROR_SDIO_ENABLE_FUNCTION                           	 = 0x802f2008,
	SCE_BT_ERROR_SDIO_DISABLE_FUNCTION                          	 = 0x802f2009,
	SCE_BT_ERROR_SDIO_SET_BLOCK_LEN                             	 = 0x802f200a,
	SCE_BT_ERROR_SDIO_SET_BUS_SPEED                             	 = 0x802f200b,
	SCE_BT_ERROR_SDIO_READ_DIR                                  	 = 0x802f200c,
	SCE_BT_ERROR_SDIO_WRITE_DIR                                 	 = 0x802f200d,
	SCE_BT_ERROR_SDIO_READ_FIX                                  	 = 0x802f200e,
	SCE_BT_ERROR_SDIO_WRITE_FIX                                 	 = 0x802f200f,
	SCE_BT_ERROR_TSLEEP                                         	 = 0x802f2010,
	SCE_BT_ERROR_GET_DEBUG_INFO_INVALID_REQUEST                 	 = 0x802f2101,
	SCE_BT_ERROR_SET_DEBUG_INFO_INVALID_REQUEST                 	 = 0x802f2102,
	SCE_BT_ERROR_GET_DEBUG_INFO_INVALID_SIZE                    	 = 0x802f2103,
	SCE_BT_ERROR_SET_DEBUG_INFO_INVALID_SIZE                    	 = 0x802f2104,
	SCE_BT_ERROR_GET_DEBUG_INFO_INVALID_ARGUMENT                	 = 0x802f2105,
	SCE_BT_ERROR_SET_DEBUG_INFO_INVALID_ARGUMENT                	 = 0x802f2106,
	SCE_BT_ERROR_GET_DEBUG_INFO_INVALID_STATE                   	 = 0x802f2107,
	SCE_BT_ERROR_SET_DEBUG_INFO_INVALID_STATE                   	 = 0x802f2108,
	SCE_BT_ERROR_GET_DEBUG_INFO_NOT_CONNECTED                   	 = 0x802f2109,
	SCE_BT_ERROR_SET_DEBUG_INFO_NOT_CONNECTED                   	 = 0x802f210a,
	SCE_BT_ERROR_PIN_IS_LE                                      	 = 0x802f2201,
	SCE_BT_ERROR_CONNECT_START_IS_LE                            	 = 0x802f2202,
	SCE_BT_ERROR_AVCTP_IS_LE                                    	 = 0x802f2203,
	SCE_BT_ERROR_HID_IS_LE                                      	 = 0x802f2204,
	SCE_BT_ERROR_AUDIO_START_IS_LE                              	 = 0x802f2205,
	SCE_BT_ERROR_AUDIO_STOP_IS_LE                               	 = 0x802f2206,
	SCE_BT_ERROR_AUDIO_SEND_IS_LE                               	 = 0x802f2207,
	SCE_BT_ERROR_AUDIO_RECV_IS_LE                               	 = 0x802f2208,
	SCE_BT_ERROR_AUDIO_FREQ_IS_LE                               	 = 0x802f2209,
	SCE_BT_ERROR_ATT_BASE                                       	 = 0x802f2300,
	SCE_BT_ERROR_ATT_INVALID_HANDLE                             	 = 0x802f2301,
	SCE_BT_ERROR_ATT_READ_NOT_PERMITTED                         	 = 0x802f2302,
	SCE_BT_ERROR_ATT_WRITE_NOT_PERMITTED                        	 = 0x802f2303,
	SCE_BT_ERROR_ATT_INVALID_PDU                                	 = 0x802f2304,
	SCE_BT_ERROR_ATT_INSUFFICIENT_AUTHENTICATION                	 = 0x802f2305,
	SCE_BT_ERROR_ATT_REQUEST_NOT_SUPPORTED                      	 = 0x802f2306,
	SCE_BT_ERROR_ATT_INVALID_OFFSET                             	 = 0x802f2307,
	SCE_BT_ERROR_ATT_INSUFFICIENT_AUTHORIZATION                 	 = 0x802f2308,
	SCE_BT_ERROR_ATT_PEPARE_QUEUE_FULL                          	 = 0x802f2309,
	SCE_BT_ERROR_ATT_ATTRIBUTE_NOT_FOUND                        	 = 0x802f230a,
	SCE_BT_ERROR_ATT_ATTRIBUTE_NOT_LONG                         	 = 0x802f230b,
	SCE_BT_ERROR_ATT_INSUFFICIENT_ENCRYPTION_KEY_SIZE           	 = 0x802f230c,
	SCE_BT_ERROR_ATT_INVALID_ATTRIBUTE_VALUE_LENGTH             	 = 0x802f230d,
	SCE_BT_ERROR_ATT_UNLIKELY_ERROR                             	 = 0x802f230e,
	SCE_BT_ERROR_ATT_INSUFFICIENT_ENCRYPTION                    	 = 0x802f230f,
	SCE_BT_ERROR_ATT_UNSUPPORTED_GROUP_TYPE                     	 = 0x802f2310,
	SCE_BT_ERROR_ATT_INSUFFICIENT_RESOURCES                     	 = 0x802f2311,
	SCE_BT_ERROR_ATT_APPLICATION_ERROR_LO                       	 = 0x802f2380,
	SCE_BT_ERROR_ATT_APPLICATION_ERROR_HI                       	 = 0x802f23ff,
	SCE_BT_ERROR_GATT_INVALID_NO                                	 = 0x802f2401,
	SCE_BT_ERROR_GATT_NOT_CONNECTED                             	 = 0x802f2402,
	SCE_BT_ERROR_GATT_BUSY                                      	 = 0x802f2403,
	SCE_BT_ERROR_GATT_INVALID_HANDLE                            	 = 0x802f2404,
	SCE_BT_ERROR_GATT_INVALID_FLAGS                             	 = 0x802f2405,
	SCE_BT_ERROR_GATT_INVALID_SIZE                              	 = 0x802f2406,
	SCE_BT_ERROR_GATT_NOT_LE                                    	 = 0x802f2407,
	SCE_BT_ERROR_GATT_TOO_BIG_RECORD                            	 = 0x802f2408,
	SCE_BT_ERROR_GATT_NOT_YET                                   	 = 0x802f2409,
	SCE_BT_ERROR_GATT_DISCONNECT                                	 = 0x802f240a,
	SCE_BT_ERROR_GATT_TSLEEP                                    	 = 0x802f240b,
	SCE_BT_ERROR_GATT_ENTER                                     	 = 0x802f240c,
	SCE_BT_ERROR_GATT_TOO_BIG_BUFFER                            	 = 0x802f240d,
	SCE_BT_ERROR_SM_INVALID_KEY_LENGTH                          	 = 0x802f2501,
	SCE_BT_ERROR_SM_NOT_DIGIT                                   	 = 0x802f2502,
	SCE_BT_ERROR_SM_NO_REQ                                      	 = 0x802f2503,
	SCE_BT_ERROR_SM_NOT_NEEDED_PIN                              	 = 0x802f2504,
	SCE_BT_ERROR_SM_INVALID_CONFIRM_REPLY                       	 = 0x802f2505,
	SCE_BT_ERROR_LE_SET_ADVERTISING_INVALID_REQ                 	 = 0x802f2601,
	SCE_BT_ERROR_LE_SET_ADVERTISING_INVALID_LENGTH              	 = 0x802f2602,
	SCE_BT_ERROR_LE_SET_ADVERTISING_INVALID_INTERVAL_MIN        	 = 0x802f2603,
	SCE_BT_ERROR_LE_SET_ADVERTISING_INVALID_INTERVAL_MAX        	 = 0x802f2604,
	SCE_BT_ERROR_LE_SET_ADVERTISING_INVALID_OWN_ADDRESS_TYPE    	 = 0x802f2605,
	SCE_BT_ERROR_LE_SET_ADVERTISING_INVALID_DIRECT_ADDRESS_TYPE 	 = 0x802f2606,
	SCE_BT_ERROR_LE_SET_ADVERTISING_INVALID_DIRECT_ADDRESS      	 = 0x802f2607,
	SCE_BT_ERROR_LE_SET_SCAN_INVALID_REQ                        	 = 0x802f2701,
	SCE_BT_ERROR_LE_SET_SCAN_INVALID_LENGTH                     	 = 0x802f2702,
	SCE_BT_ERROR_LE_SET_SCAN_INVALID_INTERVAL                   	 = 0x802f2703,
	SCE_BT_ERROR_LE_SET_SCAN_INVALID_WINDOW                     	 = 0x802f2704,
	SCE_BT_ERROR_LE_SET_SCAN_INVALID_OWN_ADDRESS_TYPE           	 = 0x802f2705,
	SCE_BT_ERROR_LE_GET_ADVERTISING_NOT_FOUND                   	 = 0x802f2801,
	SCE_BT_ERROR_LE_CREATE_CONNECTION_INVALID_SCAN_INTERVAL     	 = 0x802f2901,
	SCE_BT_ERROR_LE_CREATE_CONNECTION_INVALID_SCAN_WINDOW       	 = 0x802f2902,
	SCE_BT_ERROR_LE_CREATE_CONNECTION_INVALID_PEER_ADDRESS      	 = 0x802f2903,
	SCE_BT_ERROR_LE_CREATE_CONNECTION_INVALID_OWN_ADDRESS_TYPE  	 = 0x802f2904,
	SCE_BT_ERROR_LE_CREATE_CONNECTION_INVALID_INTERVAL_MIN      	 = 0x802f2905,
	SCE_BT_ERROR_LE_CREATE_CONNECTION_INVALID_INTERVAL_MAX      	 = 0x802f2906,
	SCE_BT_ERROR_LE_CREATE_CONNECTION_INVALID_LATENCY           	 = 0x802f2907,
	SCE_BT_ERROR_LE_CREATE_CONNECTION_INVALID_TIMEOUT           	 = 0x802f2908,
	SCE_BT_ERROR_LE_CREATE_CONNECTION_REG_FULL                  	 = 0x802f2909,
	SCE_BT_ERROR_LE_CREATE_CONNECTION_REG_ERROR                 	 = 0x802f290a,
	SCE_BT_ERROR_LE_CREATE_CONNECTION_CONNECTED                 	 = 0x802f290b,
	SCE_BT_ERROR_LE_CREATE_CONNECTION_FULL                      	 = 0x802f290c,
	SCE_BT_ERROR_LE_CREATE_CONNECTION_BUSY                      	 = 0x802f290d,
	SCE_BT_ERROR_ATT_READ_INVALID_NO                            	 = 0x802f2a01,
	SCE_BT_ERROR_ATT_READ_INVALID_LENGTH                        	 = 0x802f2a02,
	SCE_BT_ERROR_ATT_READ_INVALID_INTERNAL                      	 = 0x802f2a03,
	SCE_BT_ERROR_ATT_WRITE_INVALID_NO                           	 = 0x802f2a04,
	SCE_BT_ERROR_ATT_WRITE_INVALID_LENGTH                       	 = 0x802f2a05,
	SCE_BT_ERROR_ATT_WRITE_INVALID_INTERNAL                     	 = 0x802f2a06,
	SCE_BT_ERROR_ATT_NOT_YET                                    	 = 0x802f2a07,
	SCE_BT_ERROR_LE_NOT_SUPPORTED                               	 = 0x802f2b01,
	SCE_BT_ERROR_PAIRING_OOB_TIMEOUT                            	 = 0x802f3101,
	SCE_BT_ERROR_PAIRING_OOB_FULL                               	 = 0x802f3102,
	SCE_BT_ERROR_PAIRING_OOB_CAN_NOT_DISCONNECT                 	 = 0x802f3103,
	SCE_BT_ERROR_PAIRING_OOB_INTERNAL_ERROR                     	 = 0x802f3104,
	SCE_BT_ERROR_NOT_READY                                      	 = 0x802f3201,
	SCE_BT_ERROR_GET_JACK_STATUS_NOT_CONNECTED                  	 = 0x802f3301,
	SCE_BT_ERROR_TOO_MANY_CONNECTION                            	 = 0x802f3401,
	SCE_BT_ERROR_TOO_MANY_HID                                   	 = 0x802f3402,
	SCE_BT_ERROR_NOT_SUPPORTED_DEVICE                           	 = 0x802f3403,
	SCE_BT_ERROR_JEDI_VOLUME_GAIN_NOT_CONNECTED                 	 = 0x802f3501,
	SCE_BT_ERROR_JEDI_SNIFF_NOT_CONNECTED                       	 = 0x802f3601,
	SCE_BT_ERROR_JEDI_SNIFF_NOT_JEDI                            	 = 0x802f3602
} SceBtErrorCode;

typedef struct SceBtRegisteredInfo {
	unsigned char  mac[6];
	unsigned short unk0;
	unsigned int   bt_class;
	unsigned int   unk1;
	unsigned int   unk2;
	unsigned short vid;
	unsigned short pid;
	unsigned int   unk3;
	unsigned int   unk4;
	char           name[128];
	unsigned char  unk5[0x60];
} SceBtRegisteredInfo;

typedef struct SceBtEvent {
	union {
		unsigned char data[0x10];
		struct {
			unsigned char  id;
			unsigned char  unk1;
			unsigned short unk2;
			unsigned int   unk3;
			unsigned int   mac0;
			unsigned int   mac1;
		};
	};
} SceBtEvent;

typedef void (*SceBtCallback)(int r0, int r1, int r2, int r3);

typedef struct _SceBtHidRequest {
	uint32_t unk00;
	uint32_t unk04;
	uint8_t  type;    //!< 0 = read?, 1 = write?, 2 = feature?, 3 = ?
	uint8_t  unk09;
	uint8_t  unk0A;
	uint8_t  unk0B;
	void     *buffer;
	uint32_t length;
	struct   _SceBtHidRequest *next;
} __attribute__((packed)) SceBtHidRequest;

int sceBtAvrcpReadVolume(int r0, int r1, int r2, int r3);
int sceBtAvrcpSendButton(int r0, int r1, int r2, int r3);
int sceBtAvrcpSendVolume(int r0, int r1, int r2, int r3);
int sceBtAvrcpSetPlayStatus(int r0, int r1, int r2, int r3);
int sceBtAvrcpSetTitle(int r0, int r1, int r2, int r3);
int sceBtDeleteRegisteredInfo(unsigned int mac0, unsigned int mac1);
int sceBtFreqAudio(int r0, int r1, int r2, int r3);
int sceBtGetConfiguration(void); // returns 0x0 BT disabled, 0x9 if enabled
int sceBtGetConnectingInfo(unsigned int mac0, unsigned int mac1); // 1 = disconnected?, 2 = connecting?, 5 = connected?
int sceBtGetDeviceName(unsigned int mac0, unsigned int mac1, char name[0x79]);
int sceBtGetInfoForTest(int r0, int r1, int r2, int r3);
int sceBtGetLastError(void);
int sceBtGetRegisteredInfo(int device, int unk, SceBtRegisteredInfo *info, unsigned int info_size);
int sceBtGetStatusForTest(int r0, int r1, int r2, int r3);
int sceBtGetVidPid(unsigned int mac0, unsigned int mac1, unsigned short vid_pid[2]);
int sceBtHfpGetCurrentPhoneNumber(int r0, int r1, int r2, int r3);
int sceBtHfpRequest(int r0, int r1, int r2, int r3);
int sceBtHidGetReportDescriptor(unsigned int mac0, unsigned int mac1, void *buffer, unsigned int size);
int sceBtHidTransfer(unsigned int mac0, unsigned int mac1, SceBtHidRequest *request);
int sceBtPairingOOB(int r0, int r1, int r2, int r3);
int sceBtPushBip(int r0, int r1, int r2, int r3);
int sceBtPushOpp(int r0, int r1, int r2, int r3);
int sceBtReadEvent(SceBtEvent *events, int num_events);
int sceBtRecvAudio(int r0, int r1, int r2, int r3);
int sceBtRecvBip(int r0, int r1, int r2, int r3);
int sceBtRecvOpp(int r0, int r1, int r2, int r3);
int sceBtRecvSpp(int r0, int r1, int r2, int r3);
int sceBtRegisterCallback(SceUID cb, int unused, int flags1, int flags2); // looks like flags1 is a mask for permitted MACs
int sceBtReplyPinCode(unsigned int mac0, unsigned int mac1, unsigned char *code, unsigned int length);
int sceBtReplyUserConfirmation(unsigned int mac0, unsigned int mac1, int unk);
int sceBtSendAudio(int r0, int r1, int r2, int r3);
int sceBtSendL2capEchoRequestForTest(int r0, int r1, int r2, int r3);
int sceBtSendSpp(int r0, int r1, int r2, int r3);
int sceBtSetConfiguration(int r0); //0 = disable bt, 1 = enabling, 2 = enabled 3 = disabling?
int sceBtSetContentProtection(int r0);
int sceBtSetInquiryResultForTest(unsigned char *);
int sceBtSetInquiryScan(int r0);
int sceBtSetL2capEchoResponseBufferForTest(int r0, int r1, int r2, int r3);
int sceBtSetStatusForTest(int r0, int r1, int r2, int r3);
int sceBtStartAudio(int r0, int r1, int r2, int r3);
int sceBtStartConnect(unsigned int mac0, unsigned int mac1); // mac0 can be used as a device index (already paired devices)?
int sceBtStartDisconnect(unsigned int mac0, unsigned int mac1);
int sceBtStartInquiry(void);
int sceBtStopAudio(int r0, int r1, int r2, int r3);
int sceBtStopInquiry(void);
int sceBtUnregisterCallback(SceUID cb);

#ifdef __cplusplus
}
#endif
#endif
