/*
 *  Copyright (c) 2014 Qualcomm Atheros, Inc.  All rights reserved. 
 *
 *  Qualcomm is a trademark of Qualcomm Incorporated, registered in the United
 *  States and other countries.  All Qualcomm Incorporated trademarks are used with
 *  permission.  Atheros is a trademark of Qualcomm Atheros, Inc., registered in
 *  the United States and other countries.  Other products and brand names may be
 *  trademarks or registered trademarks of their respective owners. 
 */

#ifndef _IEEE80211_RRM_H_
#define _IEEE80211_RRM_H_ 

#include <stdint.h>

#define IEEE80211_RRM_CHAN_MAX            255

#define IEEE80211_RRM_NUM_CHANREQ_MAX 5
#define IEEE80211_RRM_NUM_CHANREP_MAX 2

struct ieee80211_beaconreq_chaninfo {
    uint8_t regclass;
    uint8_t numchans;
    uint8_t channum[IEEE80211_RRM_NUM_CHANREQ_MAX];
};

typedef struct ieee80211_rrm_beaconreq_info_s {
    uint16_t   num_rpt;
    uint8_t    regclass;
    uint8_t    channum;
    uint16_t   random_ivl;
    uint16_t   duration;
    uint8_t    reqmode;
    uint8_t    reqtype;
    uint8_t    bssid[6];
    uint8_t    mode;
    uint8_t    req_ssid;
    uint8_t    rep_cond;
    uint8_t    rep_thresh;
    uint8_t    rep_detail;
    uint8_t    req_ie;
    uint8_t    num_chanrep;
    struct ieee80211_beaconreq_chaninfo
              apchanrep[IEEE80211_RRM_NUM_CHANREP_MAX];
}ieee80211_rrm_beaconreq_info_t;

typedef struct ieee80211_rrm_chloadreq_info_s{
    uint8_t dstmac[6];
    uint16_t num_rpts;
    uint8_t regclass;
    uint8_t chnum;
    uint16_t r_invl;
    uint16_t m_dur;
    uint8_t cond;
    uint8_t c_val;
}ieee80211_rrm_chloadreq_info_t;

typedef struct ieee80211_rrm_nhist_info_s{
    uint16_t num_rpts;
    uint8_t dstmac[6];
    uint8_t regclass;
    uint8_t chnum;
    uint16_t r_invl;
    uint16_t m_dur;
    uint8_t cond;
    uint8_t c_val;
}ieee80211_rrm_nhist_info_t;

typedef struct ieee80211_rrm_frame_req_info_s{
    uint8_t dstmac[6];
    uint8_t peermac[6];
    uint16_t num_rpts;
    uint8_t regclass;
    uint8_t chnum;
    uint16_t r_invl;
    uint16_t m_dur;
    uint8_t ftype;
}ieee80211_rrm_frame_req_info_t;

typedef struct ieee80211_rrm_lcireq_info_s
{
    uint8_t dstmac[6];
    uint16_t num_rpts;
    uint8_t location;
    uint8_t lat_res;
    uint8_t long_res;
    uint8_t alt_res;
    uint8_t azi_res;
    uint8_t azi_type;
}ieee80211_rrm_lcireq_info_t;

typedef struct ieee80211_rrm_stastats_info_s{
    uint8_t dstmac[6];
    uint16_t num_rpts;
    uint16_t m_dur;
    uint16_t r_invl;
    uint8_t  gid;
}ieee80211_rrm_stastats_info_t;

typedef struct ieee80211_rrm_tsmreq_info_s {
    uint16_t   num_rpt;
    uint16_t   rand_ivl;
    uint16_t   meas_dur;
    uint8_t    reqmode;
    uint8_t    reqtype;
    uint8_t    tid;
    uint8_t    macaddr[6];
    uint8_t    bin0_range;
    uint8_t    trig_cond;
    uint8_t    avg_err_thresh;
    uint8_t    cons_err_thresh;
    uint8_t    delay_thresh;
    uint8_t    meas_count;
    uint8_t    trig_timeout;
}ieee80211_rrm_tsmreq_info_t;

typedef struct ieee80211_rrm_nrreq_info_s {
    uint8_t dialogtoken;
    uint8_t ssid[32];
    uint8_t ssid_len;
}ieee80211_rrm_nrreq_info_t;

struct ieee80211_rrmreq_info {
    uint8_t rm_dialogtoken;
    uint8_t rep_dialogtoken;
    uint8_t bssid[6];
    uint16_t duration;
    uint8_t chnum;
    uint8_t regclass;
    uint8_t gid;
    uint8_t location; /* Location of requesting/reporting station */
    uint8_t lat_res;  /* Latitute resolution */
    uint8_t long_res; /* Longitude resolution */
    uint8_t alt_res;  /* Altitude resolution */
    uint8_t reject_type;
    uint8_t reject_mode;
};

typedef struct ieee80211_rrm_lci_data_s
{
  uint8_t id;
  uint8_t len;
  uint8_t lat_res;
  uint8_t alt_type;
  uint8_t long_res;
  uint8_t alt_res;
  uint8_t azi_res;
  uint8_t alt_frac;
  uint8_t datum;
  uint8_t azi_type;
  uint16_t lat_integ;
  uint16_t long_integ;
  uint16_t azimuth;
  uint32_t lat_frac;
  uint32_t long_frac;
  uint32_t alt_integ;
}ieee80211_rrm_lci_data_t;

typedef struct ieee80211_rrm_statsgid10_s{
    uint8_t ap_avg_delay;
    uint8_t be_avg_delay;
    uint8_t bk_avg_delay;
    uint8_t vi_avg_delay;
    uint8_t vo_avg_delay;
    uint16_t st_cnt;
    uint8_t ch_util;
}ieee80211_rrm_statsgid10_t;

typedef struct ieee80211_rrm_statsgid0_s{
    uint32_t txfragcnt;
    uint32_t mcastfrmcnt;
    uint32_t failcnt;
    uint32_t rxfragcnt;
    uint32_t mcastrxfrmcnt;
    uint32_t fcserrcnt;
    uint32_t txfrmcnt;
}ieee80211_rrm_statsgid0_t;

typedef struct ieee80211_rrm_statsgid1_s{
    uint32_t rty;
    uint32_t multirty;
    uint32_t frmdup;
    uint32_t rtsuccess;
    uint32_t rtsfail;
    uint32_t ackfail;
}ieee80211_rrm_statsgid1_t;

typedef struct ieee80211_rrm_statsgidupx_s {
    uint32_t qostxfragcnt;
    uint32_t qosfailedcnt;
    uint32_t qosrtycnt;
    uint32_t multirtycnt;
    uint32_t qosfrmdupcnt;
    uint32_t qosrtssuccnt;
    uint32_t qosrtsfailcnt;
    uint32_t qosackfailcnt;
    uint32_t qosrxfragcnt;
    uint32_t qostxfrmcnt;
    uint32_t qosdiscadrfrmcnt;
    uint32_t qosmpdurxcnt;
    uint32_t qosrtyrxcnt;
}ieee80211_rrm_statsgidupx_t;

typedef struct ieee80211_rrm_tsm_data_s
{
    uint8_t tid;
    uint8_t brange;
    uint8_t mac[6];
    uint32_t tx_cnt;
    uint32_t discnt;
    uint32_t multirtycnt;
    uint32_t cfpoll;
    uint32_t qdelay;
    uint32_t txdelay;
    uint32_t bin[6];
}ieee80211_rrm_tsm_data_t;

typedef struct ieee80211_frmcnt_data_s
{
    uint8_t phytype;
    uint8_t arcpi;
    uint8_t lrsni;
    uint8_t lrcpi;
    uint8_t antid;
    uint8_t ta[6];
    uint8_t bssid[6];
    uint16_t frmcnt;
}ieee80211_rrm_frmcnt_data_t;

typedef struct ieee80211_rrm_lm_data_s
{
    uint8_t tx_pow;
    uint8_t lmargin;
    uint8_t rxant;
    uint8_t txant;
    uint8_t rcpi;
    uint8_t rsni;
}ieee80211_rrm_lm_data_t;

typedef struct ieee80211_rrm_noise_data_s
{
    uint8_t antid;
    int8_t anpi;
    uint8_t ipi[11];
}ieee80211_rrm_noise_data_t;

typedef struct ieee80211_rrm_node_stats_s 
{
    ieee80211_rrm_statsgid0_t   gid0;
    ieee80211_rrm_statsgid1_t   gid1;
    ieee80211_rrm_statsgidupx_t gidupx[8]; /* from 0 to seven */
    ieee80211_rrm_statsgid10_t  gid10;
    ieee80211_rrm_tsm_data_t    tsm_data;
  
    /* as per specification length can maximum be 228 */
    ieee80211_rrm_frmcnt_data_t frmcnt_data[12];
    ieee80211_rrm_lm_data_t     lm_data;
    ieee80211_rrm_lci_data_t    ni_rrm_lciinfo; /* RRM LCI information of this node */
    ieee80211_rrm_lci_data_t    ni_vap_lciinfo; /* RRM LCI information of VAP wrt this node */
}ieee80211_rrm_node_stats_t;


/* RRM statistics */
typedef struct ieee80211_rrmstats_s 
{
    uint8_t                    chann_load[IEEE80211_RRM_CHAN_MAX];
    ieee80211_rrm_noise_data_t  noise_data[IEEE80211_RRM_CHAN_MAX];
    ieee80211_rrm_node_stats_t  ni_rrm_stats;
}ieee80211_rrmstats_t;

/* to user level */
typedef struct ieee80211_bcnrpt_s {
    uint8_t bssid[6];
    uint8_t rsni;
    uint8_t rcpi;
    uint8_t chnum;
    uint8_t more;
}ieee80211_bcnrpt_t; 

typedef struct ieee80211req_rrmstats_s {
    uint32_t index;
    uint32_t data_size;
    void *data_addr;
}ieee80211req_rrmstats_t;

#endif /* _IEEE80211_RRM_PROTO_H_ */
