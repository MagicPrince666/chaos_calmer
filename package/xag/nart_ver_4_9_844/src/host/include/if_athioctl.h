/*
 * Copyright (c) 2010, Atheros Communications Inc. 
 * All Rights Reserved.
 * 
 * Copyright (c) 2011 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * 
 */

/*
 * Ioctl-related defintions for the Atheros Wireless LAN controller driver.
 */
#ifndef _DEV_ATH_ATHIOCTL_H
#define _DEV_ATH_ATHIOCTL_H

#include <stdint.h>
#include <sys/types.h>
typedef char* caddr_t;

#ifdef VOW_LOGLATENCY
#define ATH_STATS_LATENCY_BINS 45  /* Number of 1024us bins to log latency */
#define ATH_STATS_LATENCY_CATS 5     /* Number of categories to log latency: 4 access categories + 1 combined */
#endif
/* add by David.Dai, for support ath_tool - athtweak */
#ifndef SIOC80211SCOMMONCMD
#define SIOC80211SCOMMONCMD    _IOWR('i', 247, struct ieee80211req)
#endif 
#ifndef SIOC80211GCOMMONCMD
 #define SIOC80211GCOMMONCMD    _IOWR('i', 248, struct ieee80211req)
#endif 

#define ATH_STATS_VI_LOG_LEN 10

#define MAX_BB_PANICS 3

#ifdef ATH_SUPPORT_HTC
#include "htc_host_struct.h"
#endif

#include "ah_osdep.h"

/* end add, David.Dai */
/*
 * 11n tx/rx stats
 */
struct ath_11n_stats {
    uint32_t   tx_pkts;            /* total tx data packets */
    uint32_t   tx_checks;          /* tx drops in wrong state */
    uint32_t   tx_drops;           /* tx drops due to qdepth limit */
    uint32_t   tx_minqdepth;       /* tx when h/w queue depth is low */
    uint32_t   tx_queue;           /* tx pkts when h/w queue is busy */
    uint32_t   tx_resetq;          /* tx reset queue instances */
    uint32_t   tx_comps;           /* tx completions */
    uint32_t   tx_comperror;       /* tx error completions on global failures */
    uint32_t   tx_unaggr_comperror; /* tx error completions of unaggregted frames */
    uint32_t   tx_stopfiltered;    /* tx pkts filtered for requeueing */
    uint32_t   tx_qnull;           /* txq empty occurences */
    uint32_t   tx_noskbs;          /* tx no skbs for encapsulations */
    uint32_t   tx_nobufs;          /* tx no descriptors */
    uint32_t   tx_badsetups;       /* tx key setup failures */
    uint32_t   tx_normnobufs;      /* tx no desc for legacy packets */
    uint32_t   tx_schednone;       /* tx schedule pkt queue empty */
    uint32_t   tx_bars;            /* tx bars sent */
    uint32_t   tx_legacy;          /* tx legacy frames sent */
    uint32_t   txunaggr_single;    /* tx unaggregate singles sent */
    uint32_t   txbar_xretry;       /* tx bars excessively retried */
    uint32_t   txbar_compretries;  /* tx bars retried */
    uint32_t   txbar_errlast;      /* tx bars last frame failed */
    uint32_t   tx_compunaggr;      /* tx unaggregated frame completions */
    uint32_t   txunaggr_xretry;    /* tx unaggregated excessive retries */
    uint32_t   tx_compaggr;        /* tx aggregated completions */
    uint32_t   tx_bawadv;          /* tx block ack window advanced */
    uint32_t   tx_bawretries;      /* tx block ack window retries */
    uint32_t   tx_bawnorm;         /* tx block ack window additions */
    uint32_t   tx_bawupdates;      /* tx block ack window updates */
    uint32_t   tx_bawupdtadv;      /* tx block ack window advances */
    uint32_t   tx_retries;         /* tx retries of sub frames */
    uint32_t   tx_xretries;        /* tx excessive retries of aggregates */
    uint32_t   tx_aggregates;      /* tx aggregated pkts sent */
    uint32_t   tx_sf_hw_xretries;  /* sub-frames excessively retried in h/w */
    uint32_t   tx_aggr_frames;     /* tx total frames aggregated */
    uint32_t   txaggr_noskbs;      /* tx no skbs for aggr encapsualtion */
    uint32_t   txaggr_nobufs;      /* tx no desc for aggr */
    uint32_t   txaggr_badkeys;     /* tx enc key setup failures */
    uint32_t   txaggr_schedwindow; /* tx no frame scheduled: baw limited */
    uint32_t   txaggr_single;      /* tx frames not aggregated */
    uint32_t   txaggr_mimo;        /* tx frames aggregated for mimo */
    uint32_t   txaggr_compgood;    /* tx aggr good completions */
    uint32_t   txaggr_comperror;   /* tx aggr error completions */
    uint32_t   txaggr_compxretry;  /* tx aggr excessive retries */
    uint32_t   txaggr_compretries; /* tx aggr unacked subframes */
    uint32_t   txunaggr_compretries; /* tx non-aggr unacked subframes */
    uint32_t   txaggr_prepends;    /* tx aggr old frames requeued */
    uint32_t   txaggr_filtered;    /* filtered aggr packet */
    uint32_t   txaggr_fifo;        /* fifo underrun of aggregate */
    uint32_t   txaggr_xtxop;       /* txop exceeded for an aggregate */
    uint32_t   txaggr_desc_cfgerr; /* aggregate descriptor config error */
    uint32_t   txaggr_data_urun;   /* data underrun for an aggregate */
    uint32_t   txaggr_delim_urun;  /* delimiter underrun for an aggregate */
    uint32_t   txaggr_errlast;     /* tx aggr: last sub-frame failed */
    uint32_t   txunaggr_errlast;   /* tx non-aggr: last frame failed */
    uint32_t   txaggr_longretries; /* tx aggr h/w long retries */
    uint32_t   txaggr_shortretries;/* tx aggr h/w short retries */
    uint32_t   txaggr_timer_exp;   /* tx aggr : tx timer expired */
    uint32_t   txaggr_babug;       /* tx aggr : BA bug */
    uint32_t   txrifs_single;      /* tx frames not bursted */
    uint32_t   txrifs_babug;       /* tx rifs : BA bug */
    uint32_t   txaggr_badtid;      /* tx aggr : Bad TID */
    uint32_t   txrifs_compretries; /* tx rifs unacked subframes */
    uint32_t   txrifs_bar_alloc;   /* tx rifs bars allocated */
    uint32_t   txrifs_bar_freed;   /* tx rifs bars freed */
    uint32_t   txrifs_compgood;    /* tx rifs good completions */
    uint32_t   txrifs_prepends;    /* tx rifs old frames requeued */
    uint32_t   tx_comprifs;        /* tx rifs completions */
    uint32_t   tx_compnorifs;      /* tx not a rifs completion */
    uint32_t   rx_pkts;            /* rx pkts */
    uint32_t   rx_aggr;            /* rx aggregated packets */
    uint32_t   rx_aggrbadver;      /* rx pkts with bad version */
    uint32_t   rx_bars;            /* rx bars */
    uint32_t   rx_nonqos;          /* rx non qos-data frames */
    uint32_t   rx_seqreset;        /* rx sequence resets */
    uint32_t   rx_oldseq;          /* rx old packets */
    uint32_t   rx_bareset;         /* rx block ack window reset */
    uint32_t   rx_baresetpkts;     /* rx pts indicated due to baw resets */
    uint32_t   rx_dup;             /* rx duplicate pkts */
    uint32_t   rx_baadvance;       /* rx block ack window advanced */
    uint32_t   rx_recvcomp;        /* rx pkt completions */
    uint32_t   rx_bardiscard;      /* rx bar discarded */
    uint32_t   rx_barcomps;        /* rx pkts unblocked on bar reception */
    uint32_t   rx_barrecvs;        /* rx pkt completions on bar reception */
    uint32_t   rx_skipped;         /* rx pkt sequences skipped on timeout */
    uint32_t   rx_comp_to;         /* rx indications due to timeout */
    uint32_t   rx_timer_starts;    /* rx countdown timers started */
    uint32_t   rx_timer_stops;     /* rx countdown timers stopped */ 
    uint32_t   rx_timer_run;       /* rx timeout occurences */
    uint32_t   rx_timer_more;      /* rx partial timeout of pending packets */
    uint32_t   wd_tx_active;       /* watchdog: tx is active */
    uint32_t   wd_tx_inactive;     /* watchdog: tx is not active */
    uint32_t   wd_tx_hung;         /* watchdog: tx is hung */
    uint32_t   wd_spurious;        /* watchdog: spurious tx hang */
    uint32_t   tx_requeue;         /* filter & requeue on 20/40 transitions */
    uint32_t   tx_drain_txq;       /* draining tx queue on error */
    uint32_t   tx_drain_tid;       /* draining tid buf queue on error */
    uint32_t   tx_cleanup_tid;     /* draining tid buf queue on node cleanup */
    uint32_t   tx_drain_bufs;      /* buffers drained from pending tid queue */
    uint32_t   tx_tidpaused;       /* pausing tx on tid */
    uint32_t   tx_tidresumed;      /* resuming tx on tid */
    uint32_t   tx_unaggr_filtered; /* unaggregated tx pkts filtered */
    uint32_t   tx_aggr_filtered;   /* aggregated tx pkts filtered */
    uint32_t   tx_filtered;        /* total sub-frames filtered */
    uint32_t   rx_rb_on;           /* total rb-s on  */
    uint32_t   rx_rb_off;          /* total rb-s off */
    uint32_t   rx_dsstat_err;      /* rx descriptor status corrupted */
#ifdef ATH_SUPPORT_TxBF
    uint32_t   bf_stream_miss;     /* beamform stream mismatch */ 
    uint32_t   bf_bandwidth_miss;  /* beamform bandwidth mismatch */ 
    uint32_t   bf_destination_miss;/* beamform destination mismatch */ 
#endif

};



/*
 * DFS stats
 */
#define DFS_MAX_FILTER  32

struct dfs_filter_stats {
    uint32_t       max_pri_count;
    uint32_t       max_used_pri;
    uint32_t       excess_pri;
    uint32_t       pri_threshold_reached;
    uint32_t       dur_threshold_reached;
    uint32_t       rssi_threshold_reached;
    uint32_t       filter_id;
};

struct ath_dfs_stats {
    uint32_t       dfs_stats_valid;
    uint32_t       event_count;
    uint32_t       chirp_count;
    uint32_t       num_filter;
    struct dfs_filter_stats fstat[DFS_MAX_FILTER];    
};

struct ath_bb_panic_info {
    int valid;
    uint32_t status;
    uint32_t tsf;
    uint32_t phy_panic_wd_ctl1;
    uint32_t phy_panic_wd_ctl2;
    uint32_t phy_gen_ctrl;
    uint32_t rxc_pcnt;
    uint32_t rxf_pcnt;
    uint32_t txf_pcnt;
    uint32_t cycles;
    uint32_t wd;
    uint32_t det;
    uint32_t rdar;
    uint32_t r_odfm;
    uint32_t r_cck;
    uint32_t t_odfm;
    uint32_t t_cck;
    uint32_t agc;
    uint32_t src;
};

struct ath_phy_stats {
    uint64_t   ast_tx_rts;   /* RTS success count */
    uint64_t   ast_tx_shortretry;/* tx on-chip retries (short). RTSFailCnt */
    uint64_t   ast_tx_longretry;/* tx on-chip retries (long). DataFailCnt */
    uint64_t   ast_rx_tooshort;/* rx discarded 'cuz frame too short */
    uint64_t   ast_rx_toobig;    /* rx discarded 'cuz frame too large */
    uint64_t   ast_rx_err; /* rx error */
    uint64_t   ast_rx_crcerr;    /* rx failed 'cuz of bad CRC */
    uint64_t   ast_rx_fifoerr;    /* rx failed 'cuz of FIFO overrun */
    uint64_t   ast_rx_phyerr;    /* rx PHY error summary count */
    uint64_t   ast_rx_decrypterr; /* rx decryption error */
    uint64_t   ast_rx_demicerr; /* rx demic error */
    uint64_t   ast_rx_demicok; /* rx demic ok */
    uint64_t   ast_rx_delim_pre_crcerr; /* pre-delimiter crc errors */
    uint64_t   ast_rx_delim_post_crcerr; /* post-delimiter crc errors */
    uint64_t   ast_rx_decrypt_busyerr; /* decrypt busy errors */
    uint64_t   ast_rx_phy[32];    /* rx PHY error per-code counts */
};

struct ast_mib_mac_stats {
    uint32_t   ast_ackrcv_bad;
    uint32_t   ast_rts_bad;
    uint32_t   ast_rts_good;
    uint32_t   ast_fcs_bad;
    uint32_t   ast_beacons;
#ifdef ATH_SUPPORT_HTC
    HTC_HOST_TGT_MIB_STATS  ast_tgt_stats;
#endif
};

struct ath_stats {
    uint32_t    ast_watchdog;     /* device reset by watchdog */
    uint32_t    ast_resetOnError; /* resets on error */
    uint32_t    ast_mat_ucast_encrypted;
    uint32_t    ast_mat_rx_recrypt;
    uint32_t    ast_mat_rx_decrypt;
    uint32_t    ast_mat_key_switch;
    uint32_t    ast_hardware;     /* fatal hardware error interrupts */
    uint32_t    ast_halresets;    /* HAL resets */
    uint32_t    ast_bmiss;        /* beacon miss interrupts */
    uint32_t    ast_rxorn;        /* rx overrun interrupts */
    uint32_t    ast_rxorn_bmiss;  /* rx overrun and bmiss interrupts: indicate descriptor corruption */
    uint32_t    ast_rxeol;        /* rx eol interrupts */
    uint32_t    ast_rxeol_recover;/* rx eol interrupt hang recoveries */
    uint32_t    ast_txurn;        /* tx underrun interrupts */
    uint32_t    ast_txto;         /* tx timeout interrupts */
    uint32_t    ast_cst;          /* carrier sense timeout interrupts */
    uint32_t    ast_mib;          /* mib interrupts */
    uint32_t    ast_rx;           /* rx interrupts */
    uint32_t    ast_rxdesc;       /* rx descriptor interrupts */
    uint32_t    ast_rxerr;        /* rx error interrupts */
    uint32_t    ast_rxnofrm;      /* rx no frame interrupts */
    uint32_t    ast_tx;           /* tx interrupts */
    uint32_t    ast_txdesc;       /* tx descriptor interrupts */
    uint32_t    ast_tim_timer;    /* tim timer interrupts */
    uint32_t    ast_bbevent;      /* baseband event interrupts */
    uint32_t    ast_rxphy;        /* rx phy error interrupts */
    uint32_t    ast_rxkcm;        /* rx key cache miss interrupts */
    uint32_t    ast_swba;         /* sw beacon alert interrupts */
    uint32_t    ast_brssi;        /* beacon rssi threshold interrupts */
    uint32_t    ast_bnr;          /* beacon not ready interrupts */
    uint32_t    ast_tim;          /* tim interrupts */
    uint32_t    ast_dtim;         /* dtim interrupts */
    uint32_t    ast_dtimsync;     /* dtimsync interrupts */
    uint32_t    ast_gpio;         /* general purpose IO interrupts */
    uint32_t    ast_cabend;       /* cab end interrupts */
    uint32_t    ast_tsfoor;       /* tsf out-of-range interrupts */
    uint32_t    ast_gentimer;     /* generic timer interrupts */
    uint32_t    ast_gtt;          /* global transmit timeout interrupts */
    uint32_t    ast_fatal;        /* fatal interrupts */
    uint32_t    ast_tx_packets;   /* packet sent on the interface */
    uint32_t    ast_rx_packets;   /* packet received on the interface */
    uint32_t    ast_tx_mgmt;      /* management frames transmitted */
    uint32_t    ast_tx_discard;   /* frames discarded prior to assoc */
    uint32_t    ast_tx_invalid;   /* frames discarded 'cuz device gone */
    uint32_t    ast_tx_qstop;     /* tx queue stopped 'cuz full */
    uint32_t    ast_tx_encap;     /* tx encapsulation failed */
    uint32_t    ast_tx_nonode;    /* tx failed 'cuz no node */
    uint32_t    ast_tx_nobuf;     /* tx failed 'cuz no tx buffer (data) */
    uint32_t    ast_tx_stop;      /* number of times the netif_stop called*/
    uint32_t    ast_tx_resume;    /* number of times netif_wake_queue called */
    uint32_t    ast_tx_nobufmgt;  /* tx failed 'cuz no tx buffer (mgmt)*/
    uint32_t    ast_tx_xretries;  /* tx failed 'cuz too many retries */
    uint64_t    ast_tx_hw_retries;/* tx retries in hw, not including RTS and
                                      successes.
                                      (approximation only) */
    uint64_t    ast_tx_hw_success;/* tx successes indicated by hw */
    uint32_t    ast_tx_fifoerr;   /* tx failed 'cuz FIFO underrun */
    uint32_t    ast_tx_filtered;  /* tx failed 'cuz xmit filtered */
    uint32_t    ast_tx_badrate;   /* tx failed 'cuz bogus xmit rate */
    uint32_t    ast_tx_noack;     /* tx frames with no ack marked */
    uint32_t    ast_tx_cts;       /* tx frames with cts enabled */
    uint32_t    ast_tx_shortpre;  /* tx frames with short preamble */
    uint32_t    ast_tx_altrate;   /* tx frames with alternate rate */
    uint32_t    ast_tx_protect;   /* tx frames with protection */
    uint32_t    ast_rx_orn;       /* rx failed 'cuz of desc overrun */
    uint32_t    ast_rx_badcrypt;  /* rx failed 'cuz decryption */
    uint32_t    ast_rx_badmic;    /* rx failed 'cuz MIC failure */
    uint32_t    ast_rx_nobuf;     /* rx setup failed 'cuz no skbuff */
    uint32_t    ast_rx_swdecrypt; /* rx frames sw decrypted due to key miss */
        uint32_t       ast_rx_hal_in_progress;
        uint32_t       ast_rx_num_data;
        uint32_t       ast_rx_num_mgmt;
        uint32_t       ast_rx_num_ctl;
        uint32_t       ast_rx_num_unknown;
        uint32_t       ast_max_pkts_per_intr;
#define ATH_STATS_MAX_INTR_BKT  512
    uint32_t   ast_pkts_per_intr[ATH_STATS_MAX_INTR_BKT+1]; /* counter bucket of packets handled in a single iteration */
    int8_t      ast_tx_rssi;                    /* tx rssi of last ack */
    int8_t      ast_tx_rssi_ctl0;               /* tx rssi of last ack [ctl, chain 0] */
    int8_t      ast_tx_rssi_ctl1;               /* tx rssi of last ack [ctl, chain 1] */
    int8_t      ast_tx_rssi_ctl2;               /* tx rssi of last ack [ctl, chain 2] */
    int8_t      ast_tx_rssi_ext0;               /* tx rssi of last ack [ext, chain 0] */
    int8_t      ast_tx_rssi_ext1;               /* tx rssi of last ack [ext, chain 1] */
    int8_t      ast_tx_rssi_ext2;               /* tx rssi of last ack [ext, chain 2] */
    int8_t      ast_rx_rssi;                    /* rx rssi from histogram [combined]*/
    int8_t      ast_rx_rssi_ctl0;               /* rx rssi from histogram [ctl, chain 0] */
    int8_t      ast_rx_rssi_ctl1;               /* rx rssi from histogram [ctl, chain 1] */
    int8_t      ast_rx_rssi_ctl2;               /* rx rssi from histogram [ctl, chain 2] */
    int8_t      ast_rx_rssi_ext0;               /* rx rssi from histogram [ext, chain 0] */
    int8_t      ast_rx_rssi_ext1;               /* rx rssi from histogram [ext, chain 1] */
    int8_t      ast_rx_rssi_ext2;               /* rx rssi from histogram [ext, chain 2] */
    uint32_t   ast_be_xmit;                    /* beacons transmitted */
    uint32_t   ast_be_nobuf;                    /* no skbuff available for beacon */
    uint32_t   ast_per_cal;                    /* periodic calibration calls */
    uint32_t   ast_per_calfail;                /* periodic calibration failed */
    uint32_t   ast_per_rfgain;                    /* periodic calibration rfgain reset */
    uint32_t   ast_rate_calls;                    /* rate control checks */
    uint32_t   ast_rate_raise;                    /* rate control raised xmit rate */
    uint32_t   ast_rate_drop;                    /* rate control dropped xmit rate */
    uint32_t   ast_ant_defswitch;              /* rx/default antenna switches */
    uint32_t   ast_ant_txswitch;               /* tx antenna switches */
    uint32_t   ast_ant_rx[8];                    /* rx frames with antenna */
    uint32_t   ast_ant_tx[8];                    /* tx frames with antenna */
    uint64_t   ast_rx_bytes;                    /* total number of bytes received */
    uint64_t   ast_tx_bytes;                    /* total number of bytes transmitted */
    uint32_t   ast_rx_num_qos_data[16];        /* per tid rx packets (includes duplicates)*/
    uint32_t   ast_rx_num_nonqos_data;         /* non qos rx packets    */
    uint32_t   ast_txq_packets[16];            /* perq packets sent on the interface for each category */
    uint32_t   ast_txq_xretries[16];           /* per q tx failed 'cuz too many retries */
    uint32_t   ast_txq_fifoerr[16];            /* per q tx failed 'cuz FIFO underrun */
    uint32_t   ast_txq_filtered[16];           /*per q  tx failed 'cuz xmit filtered */
    uint32_t   ast_txq_athbuf_limit[16];       /* tx dropped 'cuz of athbuf limit */
    uint32_t   ast_txq_nobuf[16];              /* tx dropped 'cuz no athbufs */
    uint8_t    ast_num_rxchain;                /* Number of rx chains */
    uint8_t    ast_num_txchain;                /* Number of tx chains */
    struct ath_11n_stats ast_11n_stats;         /* 11n statistics */
    struct ath_dfs_stats ast_dfs_stats;         /* DFS statistics */
    uint32_t   ast_bb_hang;                    /* BB hang detected */
    uint32_t   ast_mac_hang;                   /* MAC hang detected */
#if ATH_WOW
    uint32_t   ast_wow_wakeups;                /* count of hibernate and standby wakeups */
    uint32_t   ast_wow_wakeupsok;              /* count of wakeups thru WoW */
    uint32_t   ast_wow_wakeupserror;           /* count of errored wakeups */
#if ATH_WOW_DEBUG
    uint32_t   ast_normal_sleeps;              /* count of normal sleeps */
    uint32_t   ast_normal_wakeups;             /* count of normal wakeups*/
    uint32_t   ast_wow_sleeps;                 /* count of wow sleeps */
    uint32_t   ast_wow_sleeps_nonet;           /* w/o IP config */
#endif
#endif
#ifdef ATH_SUPPORT_UAPSD
    uint32_t   ast_uapsdqnulbf_unavail;        /* no qos null buffers available */
    uint32_t   ast_uapsdqnul_pkts;             /* count of qos null frames sent */
    uint32_t   ast_uapsdtriggers;              /* count of UAPSD triggers received */
    uint32_t   ast_uapsdnodeinvalid;           /* count of triggers for non-UAPSD node */
    uint32_t   ast_uapsdeospdata;              /* count of QoS Data with EOSP sent */
    uint32_t   ast_uapsddata_pkts;             /* count of UAPSD QoS Data frames sent */
    uint32_t   ast_uapsddatacomp;              /* count of UAPSD QoS Data frames completed */
    uint32_t   ast_uapsdqnulcomp;              /* count of UAPSD QoS NULL frames completed */
    uint32_t   ast_uapsddataqueued;            /* count of UAPSD QoS Data Queued */
    uint32_t   ast_uapsdedmafifofull;          /* count of UAPSD trigger frames not processed due to EDMA HW FIFO being full */
#endif
#ifdef ATH_SUPPORT_VOWEXT
    /* VOWEXT stats only. Literally some of the iqueue stats can be re-used here
     * As part of current release, all vow stats will be added extra and 
     * re-using will be thought for next release 
     */
    /*
     * ast_vow_ul_tx_calls : Number of frames Upper Layer ( ieee ) tried to send
     * over each access category. For each of the AC this would denote how many 
     * frames reached ATH layer.
     *                       
     * ast_vow_ath_txq_calls: Subset of ( ast_vow_ul_tx_calls ) that can be
     * either queued or can be sent immediate, either as an aggregate or as an
     * normal frame. This counts only frames that can be sent. 
    */
    uint32_t   ast_vow_ul_tx_calls[4]; 
    uint32_t   ast_vow_ath_txq_calls[4];
    uint32_t   ast_vow_ath_be_drop, ast_vow_ath_bk_drop;
#endif
#if ATH_SUPPORT_CFEND
    uint32_t ast_cfend_sched;			/* count of CF-END frames scheduled */
    uint32_t ast_cfend_sent;   		/* count of CF-END frames sent */
#endif
#ifdef VOW_LOGLATENCY
    uint32_t ast_retry_delay[ATH_STATS_LATENCY_CATS][ATH_STATS_LATENCY_BINS];
    uint32_t ast_queue_delay[ATH_STATS_LATENCY_CATS][ATH_STATS_LATENCY_BINS];
#endif

#ifdef UMAC_SUPPORT_VI_DBG
    uint32_t   vi_timestamp[ATH_STATS_VI_LOG_LEN];      /* h/w assigned timestamp        */
    uint8_t    vi_rssi_ctl0[ATH_STATS_VI_LOG_LEN];      /* rx frame RSSI [ctl, chain 0]  */
    uint8_t    vi_rssi_ctl1[ATH_STATS_VI_LOG_LEN];      /* rx frame RSSI [ctl, chain 1]  */
    uint8_t    vi_rssi_ctl2[ATH_STATS_VI_LOG_LEN];      /* rx frame RSSI [ctl, chain 2]  */
    uint8_t    vi_rssi_ext0[ATH_STATS_VI_LOG_LEN];      /* rx frame RSSI [ext, chain 0]  */
    uint8_t    vi_rssi_ext1[ATH_STATS_VI_LOG_LEN];      /* rx frame RSSI [ext, chain 1]  */
    uint8_t    vi_rssi_ext2[ATH_STATS_VI_LOG_LEN];      /* rx frame RSSI [ext, chain 2]  */
    uint8_t    vi_rssi[ATH_STATS_VI_LOG_LEN];
    uint8_t    vi_evm0[ATH_STATS_VI_LOG_LEN];           /* evm - chain 0                 */
    uint8_t    vi_evm1[ATH_STATS_VI_LOG_LEN];           /* evm - chain 1                 */
    uint8_t    vi_evm2[ATH_STATS_VI_LOG_LEN];           /* evm - chain 2                 */
    uint8_t    vi_rs_rate[ATH_STATS_VI_LOG_LEN];        /* h/w receive rate index        */
    uint32_t   vi_tx_frame_cnt[ATH_STATS_VI_LOG_LEN];   /* Profile count transmit frames */
    uint32_t   vi_rx_frame_cnt[ATH_STATS_VI_LOG_LEN];   /* Profile count receive frames  */
    uint32_t   vi_rx_clr_cnt[ATH_STATS_VI_LOG_LEN];     /* Profile count receive clear   */
    uint32_t   vi_rx_ext_clr_cnt[ATH_STATS_VI_LOG_LEN]; /* Profile count receive clear on ext channel */
    uint32_t   vi_cycle_cnt[ATH_STATS_VI_LOG_LEN];      /* Profile count cycle counter   */
    uint8_t    vi_stats_index;                          /* Used to index circular buffer used to hold video stats */
#endif
#ifdef ATH_SUPPORT_TxBF
#define MCS_RATE 0x1f
    uint8_t    ast_txbf;
    uint8_t    ast_lastratecode;
    uint32_t   ast_sounding_count;
    uint32_t   ast_txbf_rpt_count;
    uint32_t   ast_mcs_count[MCS_RATE+1];
#endif
#if ATH_RX_LOOPLIMIT_TIMER
    uint32_t   ast_rx_looplimit_start;
    uint32_t   ast_rx_looplimit_end;
#endif
    uint32_t   ast_chan_clr_cnt;
    uint32_t   ast_cycle_cnt;
    int16_t     ast_noise_floor;
    struct ast_mib_mac_stats ast_mib_stats;
    struct ath_bb_panic_info ast_bb_panic[MAX_BB_PANICS];
};

struct ath_stats_container {
    uint32_t         size;
    struct ath_stats  *address;
    uint32_t         offload_if;
};

struct ath_phy_stats_container {
    uint32_t              size;
    struct ath_phy_stats  *address;
};

/*
** Enumeration of parameter IDs
** This is how the external users refer to specific parameters, which is
** why it's defined in the external interface
*/

typedef enum {
    ATH_PARAM_TXCHAINMASK           =1,
    ATH_PARAM_RXCHAINMASK           =2,
    ATH_PARAM_TXCHAINMASKLEGACY     =3,
    ATH_PARAM_RXCHAINMASKLEGACY     =4,
    ATH_PARAM_CHAINMASK_SEL         =5,
    ATH_PARAM_AMPDU                 =6,
    ATH_PARAM_AMPDU_LIMIT           =7,
    ATH_PARAM_AMPDU_SUBFRAMES       =8,
    ATH_PARAM_AGGR_PROT             =9,
    ATH_PARAM_AGGR_PROT_DUR         =10,
    ATH_PARAM_AGGR_PROT_MAX         =11,
    ATH_PARAM_TXPOWER_LIMIT2G       =12,
    ATH_PARAM_TXPOWER_LIMIT5G       =13,
    ATH_PARAM_TXPOWER_OVERRIDE      =14,
    ATH_PARAM_PCIE_DISABLE_ASPM_WK  =15,
    ATH_PARAM_PCID_ASPM             =16,
    ATH_PARAM_BEACON_NORESET        =17,
    ATH_PARAM_CAB_CONFIG            =18,
    ATH_PARAM_ATH_DEBUG             =19,
    ATH_PARAM_ATH_TPSCALE           =20,
    ATH_PARAM_ACKTIMEOUT            =21,
#ifdef ATH_RB
    ATH_PARAM_RX_RB                 =22,
    ATH_PARAM_RX_RB_DETECT          =23,
    ATH_PARAM_RX_RB_TIMEOUT         =24,
    ATH_PARAM_RX_RB_SKIPTHRESH      =25,
#endif
    ATH_PARAM_AMSDU_ENABLE          =26,
#if ATH_SUPPORT_IQUE
    ATH_PARAM_RETRY_DURATION        =27,
    ATH_PARAM_HBR_HIGHPER           =28,
    ATH_PARAM_HBR_LOWPER            =29,
#endif
    ATH_PARAM_RX_STBC               =30,
    ATH_PARAM_TX_STBC               =31,
    ATH_PARAM_LDPC                  =32,
    ATH_PARAM_LIMIT_LEGACY_FRM      =33,
    ATH_PARAM_TOGGLE_IMMUNITY       =34,
    ATH_PARAM_WEP_TKIP_AGGR_TX_DELIM    =35,
    ATH_PARAM_WEP_TKIP_AGGR_RX_DELIM    =36,
    ATH_PARAM_GPIO_LED_CUSTOM       =37,
    ATH_PARAM_SWAP_DEFAULT_LED      =38,
#if defined(ATH_SUPPORT_WIRESHARK)
    ATH_PARAM_TAPMONITOR            =39,
#endif
#if ATH_SUPPORT_VOWEXT
    ATH_PARAM_VOWEXT                =40,
    /*ATH_PARAM_RCA                   =41,*/ /* rate control and 
                                       aggregation parameters */
	ATH_PARAM_VSP_ENABLE            =42,
	ATH_PARAM_VSP_THRESHOLD         =43,
	ATH_PARAM_VSP_EVALINTERVAL      =44,
#endif
#if ATH_VOW_EXT_STATS
    ATH_PARAM_VOWEXT_STATS          =45,
#endif
#ifdef VOW_TIDSCHED
    ATH_PARAM_TIDSCHED              =46,
    ATH_PARAM_TIDSCHED_VOQW         =47,
    ATH_PARAM_TIDSCHED_VIQW         =48,
    ATH_PARAM_TIDSCHED_BKQW         =49,
    ATH_PARAM_TIDSCHED_BEQW         =50,
    ATH_PARAM_TIDSCHED_VOTO         =51,
    ATH_PARAM_TIDSCHED_VITO         =52,
    ATH_PARAM_TIDSCHED_BKTO         =53,
    ATH_PARAM_TIDSCHED_BETO         =54,
#endif
#if  ATH_SUPPORT_AOW
    ATH_PARAM_SW_RETRY_LIMIT        =55,
    ATH_PARAM_AOW_LATENCY           =56,
    ATH_PARAM_AOW_STATS             =57,
    ATH_PARAM_AOW_LIST_AUDIO_CHANNELS   =58,
    ATH_PARAM_AOW_PLAY_LOCAL            =59,
    ATH_PARAM_AOW_CLEAR_AUDIO_CHANNELS  =60,
    ATH_PARAM_AOW_ER                    =61,
    ATH_PARAM_AOW_EC                    =62,
    ATH_PARAM_AOW_EC_FMAP               =63,
#endif  /* ATH_SUPPORT_AOW */
    /*Thresholds for interrupt mitigation*/
    ATH_PARAM_RIMT_FIRST                =64,
    ATH_PARAM_RIMT_LAST                 =65,
    ATH_PARAM_TIMT_FIRST                =66,
    ATH_PARAM_TIMT_LAST                 =67,
#ifdef VOW_LOGLATENCY
    ATH_PARAM_LOGLATENCY                =68,
#endif
    ATH_PARAM_TXBF_SW_TIMER             =69,
    ATH_PARAM_PHYRESTART_WAR            =70,
    ATH_PARAM_CHANNEL_SWITCHING_TIME_USEC    =71,
    ATH_PARAM_KEYSEARCH_ALWAYS_WAR      = 72,
#ifdef ATH_SUPPORT_DYN_TX_CHAINMASK
    ATH_PARAM_DYN_TX_CHAINMASK          =73,
#endif /* ATH_SUPPORT_DYN_TX_CHAINMASK */
#if ATH_SUPPORT_VOWEXT
    ATH_PARAM_VSP_STATS                 =74,
    ATH_PARAM_VSP_STATSCLR              =75,
#endif

#if UMAC_SUPPORT_SMARTANTENNA
    ATH_PARAM_SMARTANTENNA          = 76,
#endif    
#if ATH_SUPPORT_AGGR_BURST
    ATH_PARAM_AGGR_BURST                =77,
    ATH_PARAM_AGGR_BURST_DURATION       =78,
#endif

#if ATH_SUPPORT_FLOWMAC_MODULE
    ATH_PARAM_FLOWMAC                   =79,
#endif
    ATH_PARAM_BCN_BURST                 =80,
#if ATH_ANI_NOISE_SPUR_OPT
    ATH_PARAM_NOISE_SPUR_OPT            =81,
#endif
    ATH_PARAM_DCS_ENABLE                =82,
#if UMAC_SUPPORT_PERIODIC_PERFSTATS
    ATH_PARAM_PRDPERFSTAT_THRPUT_ENAB  = 83,
    ATH_PARAM_PRDPERFSTAT_THRPUT_WIN   = 84,
    ATH_PARAM_PRDPERFSTAT_THRPUT       = 85,
    ATH_PARAM_PRDPERFSTAT_PER_ENAB     = 86,
    ATH_PARAM_PRDPERFSTAT_PER_WIN      = 87,
    ATH_PARAM_PRDPERFSTAT_PER          = 88,
#endif /* UMAC_SUPPORT_PERIODIC_PERFSTATS */
    ATH_PARAM_TOTAL_PER                = 89,
    ATH_PARAM_AMPDU_RX_BSIZE            =90,
#if ATH_SUPPORT_RX_PROC_QUOTA   
    ATH_PARAM_CNTRX_NUM                =91,
#endif   
   ATH_PARAM_RTS_CTS_RATE              =92,
#if ATH_SUPPORT_VOW_DCS
    ATH_PARAM_DCS_COCH                  =93,
    ATH_PARAM_DCS_TXERR                 =94,
    ATH_PARAM_DCS_PHYERR                =95,
#endif
#if UMAC_SUPPORT_SMARTANTENNA
    ATH_PARAM_SMARTANT_TRAIN_MODE   = 96,    /* smart antenna training mode implicit or explicit*/
    ATH_PARAM_SMARTANT_TRAIN_TYPE   = 97,    /* smart antenna train type frame base or protocol based */
    ATH_PARAM_SMARTANT_PKT_LEN      = 98,    /* packet length of the training packet */
    ATH_PARAM_SMARTANT_NUM_PKTS     = 99,    /* number of packets need to send for training */
    ATH_PARAM_SMARTANT_TRAIN_START  = 100,    /* start smart antenna training */
    ATH_PARAM_SMARTANT_NUM_ITR      = 101,    /* number of iterations needed for training */
    ATH_PARAM_SMARTANT_CURRENT_ANTENNA = 102, /* current smart antenna used for TX */
    ATH_PARAM_SMARTANT_DEFAULT_ANTENNA = 103, /* default antenna for RX */
    ATH_PARAM_SMARTANT_TRAFFIC_GEN_TIMER = 104,      /* Self packet generation timer value configuration */
    ATH_PARAM_SMARTANT_RETRAIN = 105,         /* Smart antenna retrain enable/disable */
    ATH_PARAM_SMARTANT_RETRAIN_THRESHOLD = 106,    /* number of packets required for retrain check */
    ATH_PARAM_SMARTANT_RETRAIN_INTERVAL = 107,    /* periodic retrain interval */
    ATH_PARAM_SMARTANT_RETRAIN_DROP = 108,    /* % change in goodput to tigger performance training */
    ATH_PARAM_SMARTANT_MIN_GOODPUT_THRESHOLD = 109, /* Minimum Good put threshold to tigger performance training */
    ATH_PARAM_SMARTANT_GOODPUT_AVG_INTERVAL =  110, /* Number of intervals Good put need to be averaged to use in performance training tigger */
#endif
#if ATH_RX_LOOPLIMIT_TIMER
    ATH_PARAM_LOOPLIMIT_NUM                 =  111,
#endif
#if ATH_TX_DUTY_CYCLE
    ATH_PARAM_TX_DUTY_CYCLE            = 112,
#endif
    ATH_PARAM_NODEBUG              = 113,
    ATH_PARAM_GET_IF_ID			= 114,
    ATH_PARAM_ALLOW_PROMISC = 115,
    ATH_PARAM_ANTENNA_GAIN_2G           =116,
    ATH_PARAM_ANTENNA_GAIN_5G           =117,
    ATH_PARAM_ACS_ENABLE_BK_SCANTIMEREN = 118,  /*Enable Acs back Ground Channel selection Scan timer in AP mode*/	
    ATH_PARAM_ACS_SCANTIME = 119,  /* ACS scan timer value in Seconds */
    ATH_PARAM_ACS_RSSIVAR = 120,   /*Negligence Delta RSSI between two channel */
    ATH_PARAM_ACS_CHLOADVAR = 121, /*Negligence Delta Channel load between two channel*/
    ATH_PARAM_ACS_LIMITEDOBSS = 122, /* Enable Limited OBSS check */
    ATH_PARAM_ACS_CTRLFLAG   = 123, /* Acs control flag for Scan timer */
    ATH_PARAM_ACS_DEBUGTRACE = 124, /* Acs Run time Debug level*/
#if ATH_SUPPORT_HYFI_ENHANCEMENTS
    ATH_PARAM_BUFF_THRESH               =125,
#endif
    ATH_PARAM_BLK_REPORT_FLOOD          =126,
    ATH_PARAM_DROP_STA_QUERY            =127,
#if ATH_SUPPORT_DSCP_OVERRIDE
    ATH_PARAM_DSCP_OVERRIDE             =128,
    ATH_PARAM_DSCP_TID_MAP_RESET        =129,
    ATH_PARAM_IGMP_DSCP_OVERRIDE        =130,
    ATH_PARAM_IGMP_DSCP_TID_MAP         =131,
    ATH_PARAM_HMMC_DSCP_OVERRIDE        =132,
    ATH_PARAM_HMMC_DSCP_TID_MAP         =133,
    ATH_PARAM_UPNP_DSCP_OVERRIDE        =134,
    ATH_PARAM_UPNP_DSCP_TID_MAP         =135,
#endif
#if ATH_SUPPORT_HYFI_ENHANCEMENTS
	ATH_PARAM_ALDSTATS                  = 136,
#endif
    ATH_PARAM_SET_FW_HANG_ID            = 137,
    ATH_PARAM_RADIO_TYPE                = 138,
    ATH_PARAM_FW_RECOVERY_ID		= 139,
    ATH_PARAM_RATE_ENABLE_RTS           = 140,
    ATH_PARAM_EN_SELECTIVE_RTS          = 141,
    ATH_PARAM_ATH_RXQ_INFO              = 142,
    ATH_PARAM_RESET_OL_STATS            = 143,
    ATH_PARAM_DISABLE_DFS               = 144,
    ATH_PARAM_DECLINE_ADDBA_ENABLE      = 145,
} ath_param_ID_t;

#define ATH_TX_POWER_SRM 0

#ifndef WIN32
struct ath_diag {
    char    ad_name[IFNAMSIZ];    /* if name, e.g. "ath0" */
    uint16_t ad_id;
#define    ATH_DIAG_DYN    0x8000        /* allocate buffer in caller */
#define    ATH_DIAG_IN    0x4000        /* copy in parameters */
#define    ATH_DIAG_OUT    0x0000        /* copy out results (always) */
#define    ATH_DIAG_ID    0x0fff
    uint16_t ad_in_size;        /* pack to fit, yech */
    caddr_t    ad_in_data;
    caddr_t    ad_out_data;
    uint32_t    ad_out_size;
};

#ifdef _MAVERICK_STA_
/* need to handle case where userland uses different sized
 * pointers than kernel, mostly x86_64 UL and 32-bit kernel
 */
struct ath_diag64 {
	char	    ad_name[IFNAMSIZ];                              /* 16 bytes */
	uint16_t   ad_id;                                          /*  2 bytes */
	uint16_t   ad_in_size;                                     /*  2 bytes */
	uint64_t   ad_in_data __attribute__((aligned(8)));         /*  8 bytes */
	uint64_t   ad_out_data;                                    /*  8 bytes */
	uint32_t	    ad_out_size;                                    /*  4 bytes */
};
#define SIOCGATHDIAG_64        _IOWR('i', 138, struct ath_diag64)
#define SIOCGATHTX99_64        _IOWR('i', 143, struct ath_diag64)

struct ath_diag32 {
	char	   ad_name[IFNAMSIZ];                              /* 16 bytes */
	uint16_t   ad_id;                                          /*  2 bytes */
	uint16_t   ad_in_size;                                     /*  2 bytes */
	uint32_t   ad_in_data;                                     /*  4 bytes */
	uint32_t   ad_out_data;                                    /*  4 bytes */
	uint32_t   ad_out_size;                                    /*  4 bytes */
};
#define SIOCGATHDIAG_32        _IOWR('i', 138, struct ath_diag32)
#define SIOCGATHTX99_32        _IOWR('i', 143, struct ath_diag32)
#endif

#define    ATH_RADAR_MUTE_TIME    1    /* Set dfs mute time for dfs test mode */

#ifdef __linux__
#define SIOCGATHSTATS       (SIOCDEVPRIVATE+0)
#define SIOCGATHDIAG        (SIOCDEVPRIVATE+1)
#define SIOCGATHCWMINFO     (SIOCDEVPRIVATE+2)
#define SIOCGATHCWMDBG      (SIOCDEVPRIVATE+3)
#define SIOCGATHSTATSCLR    (SIOCDEVPRIVATE+4)
#define SIOCGATHPHYERR      (SIOCDEVPRIVATE+5)
#define SIOCGATHEACS        (SIOCDEVPRIVATE+6)
#define SIOCGATHAOW         (SIOCDEVPRIVATE+8)
#define SIOCSATHSUSPEND     (SIOCDEVPRIVATE+10)
/* Currently exposed only for Linux, as part of some Access Point
   statistics.
   TODO: Implement for other platforms, if required. */
#define SIOCGATHPHYSTATS    (SIOCDEVPRIVATE+11)
#define SIOCG80211PROFILE     (SIOCDEVPRIVATE+12)
/* 13 for TX99 */
#define SIOCGATHPHYSTATSCUR (SIOCDEVPRIVATE+14)
#define SIOCGSETCTLPOW   	(SIOCDEVPRIVATE+15)

#define ATH_HAL_IOCTL_SETPARAM              (SIOCIWFIRSTPRIV+0)
#define ATH_HAL_IOCTL_GETPARAM              (SIOCIWFIRSTPRIV+1)
#define ATH_IOCTL_SETCOUNTRY                (SIOCIWFIRSTPRIV+2)
#define ATH_IOCTL_GETCOUNTRY                (SIOCIWFIRSTPRIV+3)
#define ATH_IOCTL_SETHWADDR                 (SIOCIWFIRSTPRIV+4)
#define ATH_IOCTL_GETHWADDR                 (SIOCIWFIRSTPRIV+5)
#define ATH_IOCTL_SET_DSCP_TID_MAP          (SIOCIWFIRSTPRIV+6)
#define ATH_IOCTL_GET_DSCP_TID_MAP          (SIOCIWFIRSTPRIV+7)
#if ATH_SUPPORT_DSCP_OVERRIDE
#define OL_ATH_IOCTL_SET_DSCP_TID_MAP       (SIOCIWFIRSTPRIV+8)
#define OL_ATH_IOCTL_GET_DSCP_TID_MAP       (SIOCIWFIRSTPRIV+9)
#endif
/* Both Direct attach and OL uses same IOCTL defines */
#define ATH_IOCTL_SET_SMART_ANTENNA   	(SIOCIWFIRSTPRIV+11)
#define ATH_IOCTL_GET_SMART_ANTENNA   	(SIOCIWFIRSTPRIV+12)





#define ATH_GET_COUNTRY                     1
#define ATH_SET_COUNTRY                     2

/* NOTE that ATH_IOCTL_EXTENDED corresponds to AR6000_IOCTL_EXTENDED from
 * the TOBA tree - this was necessary for interoperation between simulator
 * binary built in toba and the driver built in the newma tree.
 *
 * With qca_main, the simulator is built in the same workspace as the host
 * driver, but the idea of using ATH_IOCTL_EXTENDED to allow an expanded
 * range of ioctls remains.
 * The simulator ioctls are defined in sim_io.h, and start at 200.
 */
#if !defined(ATH_IOCTL_EXTENDED)
#define ATH_IOCTL_EXTENDED               (SIOCIWFIRSTPRIV+31)
#endif


/*
** We have to do a "split" of ID values, since they are all combined
** into the same table.  This value is a "shift" value for ATH parameters
*/

#define ATH_PARAM_SHIFT     0x1000
#define SPECIAL_PARAM_SHIFT 0x2000

#else /* __linux__ */

struct ath_privreq {
    char        ap_name[IFNAMSIZ];    /* if_name, e.g. "wi0" */
    uint16_t    ap_type;        /* req type */
    int16_t        ap_val;            /* Index or simple value */
    int16_t        ap_len;            /* Index or simple value */
    void        *ap_data;        /* Extra data */
};
#define SIOCATHPRIV        _IOWR('i', 140, struct ath_privreq)
#define SIOCGATHSTATS       _IOWR('i', 137, struct ifreq)
#define SIOCGATHDIAG        _IOWR('i', 138, struct ath_diag)
#define SIOCGATHCWMINFO     _IOWR('i', 139, struct ath_cwminfo)
#ifndef REMOVE_PKT_LOG
#define SIOCGATHPKT         _IOWR('i', 141, struct ath_pktlog_ioctl)
#endif /* REMOVE_PKT_LOG */
#define SIOCGATHPHYERR      _IOWR('i', 142, struct ath_diag)
#define SIOCGATHTX99        _IOWR('i', 143, struct ath_diag)
#define SIOCGATHEACS        _IOWR('i', 145, struct ifreq)
#define SIOCGATHCWMDBG      _IOWR('i', 146, struct ath_cwmdbg)
#define SIOCGATHSTATSCLR    _IOWR('i', 147, struct ifreq)

/* ifreq, for athstats */
/* the system version of struct ifreq hides ifru_data64 from us in userland */
struct	ath_ifreq {
	char	ifr_name[IFNAMSIZ];		/* if name, e.g. "en0" */
	union {
		caddr_t	ifru_data;
	} ifr_ifru;
};
#ifdef _MAVERICK_STA_
struct	ath_ifreq32 {
	char	ifr_name[IFNAMSIZ];		/* if name, e.g. "en0" */
	union {
		uint32_t	ifru_data;
	} ifr_ifru;
};

struct	ath_ifreq64 {
	char	ifr_name[IFNAMSIZ];		/* if name, e.g. "en0" */
	union {
		uint64_t	ifru_data;
	} ifr_ifru __attribute__((aligned(8)));
};
#define	aifr_data	ifr_ifru.ifru_data	/* for use by interface */
/* don't use struct ifreq anymore */
#undef SIOCGATHSTATS
#define SIOCGATHSTATS       _IOWR('i', 137, struct ath_ifreq)
#define SIOCGATHSTATS_32     _IOWR('i', 137, struct ath_ifreq32)
#define SIOCGATHSTATS_64     _IOWR('i', 137, struct ath_ifreq64)
#endif /* _MAVERICK_STA_ */

/*
 * packet_log support.
 */
#ifndef REMOVE_PKT_LOG
struct ieee80211com;
int ath_ioctl_pktlog(struct ieee80211com *, u_long, caddr_t);

struct ath_pktlog_ioctl {
    char    ap_name[IFNAMSIZ];    /* ifname, e.g. "ath0" */
    uint16_t    ap_cmd;
    uint32_t    ap_val;
    caddr_t    ap_data;
    uint32_t    ap_data_size;
};

#ifdef _MAVERICK_STA_
/* pktlog */
struct ath_pktlog_ioctl64 {
    char	ap_name[IFNAMSIZ];	/* ifname, e.g. "ath0" */       /* 16 bytes */
    uint16_t	ap_cmd;                                         /*  2 bytes */
    uint32_t	ap_val;                                         /*  4 bytes */
    uint64_t	ap_data __attribute__((aligned(8)));            /*  8 bytes */
    uint32_t	ap_data_size;                                   /*  4 bytes */
};
#define SIOCGATHPKT_64         _IOWR('i', 141, struct ath_pktlog_ioctl64)

struct ath_pktlog_ioctl32 {
    char	ap_name[IFNAMSIZ];	/* ifname, e.g. "ath0" */       /* 16 bytes */
    uint16_t	ap_cmd;                                         /*  2 bytes */
    uint32_t	ap_val __attribute__((aligned(4)));             /*  4 bytes */
    uint32_t	ap_data;                                        /*  4 bytes */
    uint32_t	ap_data_size;                                   /*  4 bytes */
};
#define SIOCGATHPKT_32         _IOWR('i', 141, struct ath_pktlog_ioctl32)
#endif /* _MAVERICK_STA_ */

#define    ATH_PKT_ENABLE        1
#define    ATH_PKT_SETSIZE       2
#define    ATH_PKT_READ          3 /* Kept for compatibility with the old code */
#define    ATH_PKT_RESET         4
#define    ATH_PKT_GETSIZE       5
#define    ATH_PKT_GETBUF        6
#define    ATH_PKT_GET_LOGSTATE  7

#endif /* REMOVE_PKT_LOG */

#endif /* __linux__ */

#endif /* #ifndef WIN32 */
#endif /* _DEV_ATH_ATHIOCTL_H */

