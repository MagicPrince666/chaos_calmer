/*
 *  Copyright (c) 2014 Qualcomm Atheros, Inc.  All rights reserved. 
 *
 *  Qualcomm is a trademark of Qualcomm Incorporated, registered in the United
 *  States and other countries.  All Qualcomm Incorporated trademarks are used with
 *  permission.  Atheros is a trademark of Qualcomm Atheros, Inc., registered in
 *  the United States and other countries.  Other products and brand names may be
 *  trademarks or registered trademarks of their respective owners. 
 */

#ifndef _IEEE80211_WNM_PROTO_H_
#define _IEEE80211_WNM_PROTO_H_ 

#include <sys/queue.h>
#include <stdint.h>
/*
 * Wireless Network management Protocol definitions
 */

/* categories */
#define IEEE80211_ACTION_CAT_WNM    10   /* Wireless Network Management */
#define IEEE80211_ACTION_CAT_UNPROTECTED_WNM    11   /* UnProtected WNM */


/* WNM action fields */
#define IEEE80211_ACTION_TIM_FRAME     0
#define IEEE80211_ACTION_BSTM_QUERY    6
#define IEEE80211_ACTION_BSTM_REQ      7
#define IEEE80211_ACTION_BSTM_RESP     8
#define IEEE80211_ACTION_FMS_REQ       9 
#define IEEE80211_ACTION_FMS_RESP      10
#define IEEE80211_ACTION_TFS_REQ       13
#define IEEE80211_ACTION_TFS_RESP      14
#define IEEE80211_ACTION_TFS_NOTIFY    15
#define IEEE80211_ACTION_WNMSLEEP_REQ  16
#define IEEE80211_ACTION_WNMSLEEP_RESP 17
#define IEEE80211_ACTION_TIM_REQ       18
#define IEEE80211_ACTION_TIM_RESP      19

/* Information Element IDs */
#define IEEE80211_ELEMID_WNMSLEEP_MODE  93
enum {
    IEEE80211_SUBELEMID_KEYDATA_GTK = 0,
    IEEE80211_SUBELEMID_KEYDATA_IGTK = 1,
};

#define IEEE80211_WNMSLEEP_ACTION_ENTER 0
#define IEEE80211_WNMSLEEP_ACTION_EXIT  1

/* WNM action frame dialogtokens */
#define IEEE80211_ACTION_RM_TOKEN    1

#define IEEE80211_TFS_DELETE   0x01
#define IEEE80211_TFS_NOTIFY   0x02
#define IEEE80211_IPV4_LEN 4
#define IEEE80211_IPV6_LEN 16

#define IEEE80211_FMS_MAX_COUNTERS     8
#define IEEE80211_FMS_STATUS_SUBELE    1
#define IEEE80211_TCLASS_STATUS_SUBELE 2

#define IEEE80211_FMS_SUBELEMENT_ID 1

#define IEEE80211_WNM_NETLINKBUF 4096
#define MAC_ADDR_LEN 6

typedef struct wnm_netlink_event {
    uint32_t type;
    uint8_t mac[MAC_ADDR_LEN];
    uint32_t datalen;
    uint8_t event_data[IEEE80211_WNM_NETLINKBUF];
}__packed wnm_netlink_event_t;


enum {
    IEEE80211_WNM_TIMREQUEST_ACCEPT,
    IEEE80211_WNM_TIMREQUEST_ACCEPT_VALID_TSF,
    IEEE80211_WNM_TIMREQUEST_DENIED,
    IEEE80211_WNM_TIMREQUEST_OVERRIDDEN,
};
enum {
    IEEE80211_WNM_FMSSUBELE_ACCEPT,
    IEEE80211_WNM_FMSSUBELE_DENY_FORMAT,
    IEEE80211_WNM_FMSSUBELE_DENY_RESOURCES,
    IEEE80211_WNM_FMSSUBELE_DENY_CLASSIFIER,
    IEEE80211_WNM_FMSSUBELE_DENY_POLICY,
    IEEE80211_WNM_FMSSUBELE_DENY_UNSPECIFIED,
    IEEE80211_WNM_FMSSUBELE_ALTE_DEL_ITVL,
    IEEE80211_WNM_FMSSUBELE_ALTE_POLICY,
    IEEE80211_WNM_FMSSUBELE_ALTE_DEL_ITVL_CHANGE,
    IEEE80211_WNM_FMSSUBELE_ALTE_MCAST_RATE_CHANGE,
    IEEE80211_WNM_FMSSUBELE_TERM_POLICY_CHANGE,
    IEEE80211_WNM_FMSSUBELE_TERM_LACK_RESOURCES,
    IEEE80211_WNM_FMSSUBELE_TERM_HIGHER_PRI,
    IEEE80211_WNM_FMSSUBELE_ALTE_MAX_DEL_ITVL_CHG,
    IEEE80211_WNM_FMSSUBELE_ALTE_TCLASS,
    IEEE80211_WNM_FMSSUBELE_RESERVED,
};


struct tclas_type3 {
    uint16_t filter_offset;
    uint8_t  *filter_value;
    uint8_t  *filter_mask;
    uint8_t  filter_len;
} __packed;


struct tclas_type4_v4 {
    uint8_t  version;
    uint8_t  src_ip[IEEE80211_IPV4_LEN];
    uint8_t  dst_ip[IEEE80211_IPV4_LEN];
    uint16_t src_port;
    uint16_t dst_port;
    uint8_t  dscp;
    uint8_t  protocol;
    uint8_t  reserved;
} __packed;

struct tclas_type4_v6 {
    uint8_t version;
    uint8_t  src_ip[IEEE80211_IPV6_LEN];
    uint8_t  dst_ip[IEEE80211_IPV6_LEN];
    uint16_t src_port;
    uint16_t dst_port;
    uint8_t  dscp;
    uint8_t  next_header;
    uint8_t  flow_label[3];
} __packed;

typedef struct tclas_element {
    uint8_t  elemid;
    uint8_t  len;
    uint8_t  up;
    uint8_t  type;
    uint8_t  mask;
    union {
        struct tclas_type3  type3;
        union {
            struct tclas_type4_v4  type4_v4;
            struct tclas_type4_v6  type4_v6;
        } type4;
    } tclas;
    TAILQ_ENTRY(tclas_element) tclas_next;
} __packed ieee80211_tclas_element;

typedef struct ieee80211_tclas_processing {
    uint8_t elem_id;
    uint8_t length;
    uint8_t tclas_process;
} __packed ieee80211_tclas_processing;
    

typedef struct ieee80211_tfs_subelement_rsp {
    uint8_t elem_id;
    uint8_t length;
    uint8_t status;
    uint8_t tfsid;
    TAILQ_ENTRY(ieee80211_tfs_subelement_rsp) tsub_next;
} __packed ieee80211_tfs_subelement_rsp;

typedef struct ieee80211_tfs_subelement_req {
    TAILQ_HEAD(, tclas_element) tclas_head;
    uint8_t elem_id;
    uint8_t length;
    struct ieee80211_tclas_processing tclasprocess;
    TAILQ_ENTRY(ieee80211_tfs_subelement_req) tsub_next;
} __packed ieee80211_tfs_subelement_req;

typedef struct ieee80211_tfs_response {
    TAILQ_ENTRY(ieee80211_tfs_response) tfs_rsp_next;
    uint8_t tfs_elemid;
    uint8_t length;
    TAILQ_HEAD(, ieee80211_tfs_subelement_rsp) tfs_rsp_sub;
} __packed ieee80211_tfs_response;

typedef struct ieee80211_tfs_request {
    TAILQ_ENTRY(ieee80211_tfs_request) tfs_req_next;
    uint8_t tfs_elemid;
    uint8_t length;
    uint8_t tfs_id;
    uint8_t tfs_action_code;
    TAILQ_HEAD(, ieee80211_tfs_subelement_req) tfs_req_sub;
} __packed ieee80211_tfs_request;

struct ieee80211_tfsreq{
    uint8_t dialogtoken;
    TAILQ_HEAD(, ieee80211_tfs_request)  tfs_req_head;
}__packed;

struct ieee80211_tfsrsp {
    uint8_t dialogtoken;
    TAILQ_HEAD(, ieee80211_tfs_response)  tfs_rsp_head;
}__packed;

struct ieee80211_bstm_reqinfo {
    uint8_t dialogtoken;
    uint8_t candidate_list;
    uint8_t disassoc;
    uint16_t disassoc_timer;
    uint8_t validity_itvl;
} __packed;

enum IEEE80211_TFS_ERRORS {
    IEEE80211_TFS_ACCEPT = 0,
    IEEE80211_TFS_INVALID_CLASSIFIER,
    IEEE80211_TFS_RESOURCE_UNAVAILABLE,
    IEEE80211_TFS_REASON_UNKNOWN = 5,
};

/* Flexible Multicast Service(FMS) Types */

typedef struct ieee80211_rate_identifier_s {
    uint8_t mask;
    uint8_t mcs_idx;
    uint16_t rate;
}__packed ieee80211_fms_rate_identifier_t;

typedef struct ieee80211_fmsreq_subele_s
{
    TAILQ_ENTRY(ieee80211_fmsreq_subele_s) fmssubele_next;
    uint8_t accepted;
    uint8_t num_tclas;
    uint8_t elem_id;
    uint8_t len;
    uint8_t del_itvl;
    uint8_t max_del_itvl;
    ieee80211_fms_rate_identifier_t rate_id;
    uint8_t mcast_addr[6];
    TAILQ_HEAD(, tclas_element) tclas_head;
    struct ieee80211_tclas_processing tclasprocess;
}__packed ieee80211_fmsreq_subele_t;


typedef struct ieee80211_fms_subelement_status_s 
{
    TAILQ_ENTRY (ieee80211_fms_subelement_status_s) subele_status_next;
    uint8_t len;
    uint8_t element_status;
    uint8_t del_itvl;
    uint8_t max_del_itvl;
    uint8_t fmsid;
    uint8_t fms_counter;
    ieee80211_fms_rate_identifier_t rate_id;
    uint8_t mcast_addr[6];
}ieee80211_fms_subelement_status_t;

typedef struct ieee80211_tclass_subelement_status_s
{
    uint8_t subelementid;
    uint8_t len;
    uint8_t fmsid;
    TAILQ_HEAD(, tclas_element) tclas_head;
    ieee80211_tclas_processing tclasprocess;
}ieee80211_tclass_subelement_status_t;

typedef struct ieee80211_fms_status_subelement_s 
{
    TAILQ_ENTRY(ieee80211_fms_status_subelement_s) status_subele_next;
    uint8_t subelementid;
    void     *subele_status;
}ieee80211_fms_status_subelement_t;

typedef struct ieee80211_fms_response_s
{ 
    TAILQ_ENTRY(ieee80211_fms_response_s) fmsrsp_next;
    uint8_t elemid;
    uint8_t len;
    uint8_t fms_token;
    TAILQ_HEAD(, ieee80211_fms_status_subelement_s) status_subele_head;
}ieee80211_fms_response_t;


typedef struct ieee80211_fms_request_s {
    TAILQ_ENTRY(ieee80211_fms_request_s) fmsreq_next;
    uint8_t elem_id;
    uint8_t len;
    uint8_t fms_token;
    TAILQ_HEAD(, ieee80211_fmsreq_subele_s) fmssubele_head;
}ieee80211_fms_request_t;

typedef struct ieee80211_fmsreq_active_element {
    TAILQ_ENTRY(ieee80211_fmsreq_active_element) fmsreq_act_next;
    uint8_t fms_token;
    TAILQ_HEAD(, ieee80211_fms_act_stream_ptr) fmsact_strmptr_head;
}ieee80211_fmsreq_active_element_t;

struct ieee80211_fmsreq {
    uint8_t dialog_token;
    TAILQ_HEAD(, ieee80211_fms_request_s) fmsreq_head;
};

struct ieee80211_fmsrsp {
    uint8_t dialog_token;
    TAILQ_HEAD(, ieee80211_fms_response_s) fmsrsp_head;
};

typedef struct ieee80211_fms_action_hdr_s {
    uint8_t  ia_category;
    uint8_t  ia_action;
    uint8_t  dialogtoken;
    uint8_t  fms_ies[1];
} __packed ieee80211_fms_action_hdr_t;

typedef struct ieee80211_fms_status_tclass_subelement_s {
    uint8_t subelement_id;
    uint8_t len;
    uint8_t fmsid;
    uint8_t tclass_elements[1];
}__packed ieee80211_fms_status_tclass_subelement_t;

typedef struct ieee80211_fms_status_subelements_s {
    uint8_t subelement_id;
    uint8_t len;
    uint8_t element_status;
    uint8_t del_itvl;
    uint8_t max_del_itvl;
    uint8_t fmsid;
    uint8_t fms_counter;
    ieee80211_fms_rate_identifier_t rate_id;
    uint8_t mcast_addr[6];
}__packed ieee80211_fms_status_subelements_t;

typedef struct ieee80211_fms_hdr_s {
    uint8_t elementid;
    uint8_t len;
    uint8_t fms_token;
}__packed ieee80211_fms_hdr_t;

typedef struct ieee80211_fms_descr_s {
    uint8_t elementid;
    uint8_t len;
    uint8_t num_ctrs;
    uint8_t fms_ctrs[1];
}__packed ieee80211_fms_descr_t;

typedef struct ieee80211_fms_req_s {
    ieee80211_fms_hdr_t hdr;
    uint8_t subelements[1];
}__packed ieee80211_fms_req_t;

typedef struct ieee80211_fms_resp_s {
    ieee80211_fms_hdr_t hdr;
    uint8_t subelements[1];
}__packed ieee80211_fms_resp_t;

#endif /* _IEEE80211_WNM_PROTO_H_ */
