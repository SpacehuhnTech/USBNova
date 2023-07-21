/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "locale.h"

#include "mac/locale_be_mac.h"
#include "mac/locale_bg_mac.h"
#include "mac/locale_ca_fr_mac.h"
#include "mac/locale_ch_de_mac.h"
#include "mac/locale_ch_fr_mac.h"
#include "mac/locale_cz_mac.h"
#include "mac/locale_de_mac.h"
#include "mac/locale_dk_mac.h"
#include "mac/locale_ee_mac.h"
#include "mac/locale_es_mac.h"
#include "mac/locale_es_la_mac.h"
#include "mac/locale_fi_mac.h"
#include "mac/locale_fr_mac.h"
#include "mac/locale_gb_mac.h"
#include "mac/locale_gr_mac.h"
#include "mac/locale_hr_mac.h"
#include "mac/locale_hu_mac.h"
#include "mac/locale_in_mac.h"
#include "mac/locale_is_mac.h"
#include "mac/locale_it_mac.h"
#include "mac/locale_lt_mac.h"
#include "mac/locale_lv_mac.h"
#include "mac/locale_nl_mac.h"
#include "mac/locale_no_mac.h"
#include "mac/locale_pl_mac.h"
#include "mac/locale_pt_mac.h"
#include "mac/locale_pt_br_mac.h"
#include "mac/locale_ro_mac.h"
#include "mac/locale_ru_mac.h"
#include "mac/locale_se_mac.h"
#include "mac/locale_si_mac.h"
#include "mac/locale_sk_mac.h"
#include "mac/locale_tr_mac.h"
#include "mac/locale_ua_mac.h"
#include "mac/locale_us_mac.h"
#include "win/locale_be_win.h"
#include "win/locale_bg_win.h"
#include "win/locale_ca_cms_win.h"
#include "win/locale_ca_fr_win.h"
#include "win/locale_ch_de_win.h"
#include "win/locale_ch_fr_win.h"
#include "win/locale_cz_win.h"
#include "win/locale_de_win.h"
#include "win/locale_dk_win.h"
#include "win/locale_ee_win.h"
#include "win/locale_es_la_win.h"
#include "win/locale_es_win.h"
#include "win/locale_fi_win.h"
#include "win/locale_fr_win.h"
#include "win/locale_gb_win.h"
#include "win/locale_gr_win.h"
#include "win/locale_hr_win.h"
#include "win/locale_hu_win.h"
#include "win/locale_ie_win.h"
#include "win/locale_in_win.h"
#include "win/locale_is_win.h"
#include "win/locale_it_win.h"
#include "win/locale_lt_win.h"
#include "win/locale_lv_win.h"
#include "win/locale_nl_win.h"
#include "win/locale_no_win.h"
#include "win/locale_pl_win.h"
#include "win/locale_pt_br_win.h"
#include "win/locale_pt_win.h"
#include "win/locale_ro_win.h"
#include "win/locale_ru_win.h"
#include "win/locale_se_win.h"
#include "win/locale_si_win.h"
#include "win/locale_sk_win.h"
#include "win/locale_tr_win.h"
#include "win/locale_ua_win.h"
#include "win/locale_us_win.h"


#include <cstring> // strncmp

namespace locale {
    // ===== PUBLIC ===== //
    hid_locale_t* get_default() {
        return &locale_us_win;
    }

    hid_locale_t* get(const char* name) {
        if (strncmp(name, "BE_MAC", 6) == 0) return &locale_be_mac;
        else if (strncmp(name, "BG_MAC", 6) == 0) return &locale_bg_mac;
        else if ((strncmp(name, "CA-FR_MAC", 9) == 0) || (strncmp(name, "CA_FR_MAC", 9) == 0)) return &locale_ca_fr_mac;
        else if ((strncmp(name, "CH-DE_MAC", 9) == 0) || (strncmp(name, "CH_DE_MAC", 9) == 0)) return &locale_ch_de_mac;
        else if ((strncmp(name, "CH-FR_MAC", 9) == 0) || (strncmp(name, "CH_FR_MAC", 9) == 0)) return &locale_ch_fr_mac;
        else if (strncmp(name, "CZ_MAC", 6) == 0) return &locale_cz_mac;
        else if (strncmp(name, "DE_MAC", 6) == 0) return &locale_de_mac;
        else if (strncmp(name, "DK_MAC", 6) == 0) return &locale_dk_mac;
        else if (strncmp(name, "EE_MAC", 6) == 0) return &locale_ee_mac;
        else if (strncmp(name, "ES_MAC", 6) == 0) return &locale_es_mac;
        else if ((strncmp(name, "ES-LA_MAC", 9) == 0) || (strncmp(name, "ES_LA_MAC", 9) == 0)) return &locale_es_la_mac;
        else if (strncmp(name, "FI_MAC", 6) == 0) return &locale_fi_mac;
        else if (strncmp(name, "FR_MAC", 6) == 0) return &locale_fr_mac;
        else if (strncmp(name, "GB_MAC", 6) == 0) return &locale_gb_mac;
        else if (strncmp(name, "GR_MAC", 6) == 0) return &locale_gr_mac;
        else if (strncmp(name, "HR_MAC", 6) == 0) return &locale_hr_mac;
        else if (strncmp(name, "HU_MAC", 6) == 0) return &locale_hu_mac;
        else if (strncmp(name, "IN_MAC", 6) == 0) return &locale_in_mac;
        else if (strncmp(name, "IS_MAC", 6) == 0) return &locale_is_mac;
        else if (strncmp(name, "IT_MAC", 6) == 0) return &locale_it_mac;
        else if (strncmp(name, "LT_MAC", 6) == 0) return &locale_lt_mac;
        else if (strncmp(name, "LV_MAC", 6) == 0) return &locale_lv_mac;
        else if (strncmp(name, "NL_MAC", 6) == 0) return &locale_nl_mac;
        else if (strncmp(name, "NO_MAC", 6) == 0) return &locale_no_mac;
        else if (strncmp(name, "PL_MAC", 6) == 0) return &locale_pl_mac;
        else if (strncmp(name, "PT_MAC", 6) == 0) return &locale_pt_mac;
        else if ((strncmp(name, "PT-BR_MAC", 9) == 0) || (strncmp(name, "PT_BR_MAC", 9) == 0)) return &locale_pt_br_mac;
        else if (strncmp(name, "RO_MAC", 6) == 0) return &locale_ro_mac;
        else if (strncmp(name, "RU_MAC", 6) == 0) return &locale_ru_mac;
        else if (strncmp(name, "SE_MAC", 6) == 0) return &locale_se_mac;
        else if (strncmp(name, "SI_MAC", 6) == 0) return &locale_si_mac;
        else if (strncmp(name, "SK_MAC", 6) == 0) return &locale_sk_mac;
        else if (strncmp(name, "TR_MAC", 6) == 0) return &locale_tr_mac;
        else if (strncmp(name, "UA_MAC", 6) == 0) return &locale_ua_mac;
        else if (strncmp(name, "US_MAC", 6) == 0) return &locale_us_mac;
        else if (strncmp(name, "BE", 2) == 0) return &locale_be_win;
        else if (strncmp(name, "BG", 2) == 0) return &locale_bg_win;
        else if ((strncmp(name, "CA-CMS", 6) == 0) || (strncmp(name, "CA_CMS", 6) == 0)) return &locale_ca_cms_win;
        else if ((strncmp(name, "CA-FR", 5) == 0) || (strncmp(name, "CA_FR", 5) == 0)) return &locale_ca_fr_win;
        else if ((strncmp(name, "CH-DE", 5) == 0) || (strncmp(name, "CH_DE", 5) == 0)) return &locale_ch_de_win;
        else if ((strncmp(name, "CH-FR", 5) == 0) || (strncmp(name, "CH_FR", 5) == 0)) return &locale_ch_fr_win;
        else if (strncmp(name, "CZ", 2) == 0) return &locale_cz_win;
        else if (strncmp(name, "DE", 2) == 0) return &locale_de_win;
        else if (strncmp(name, "DK", 2) == 0) return &locale_dk_win;
        else if (strncmp(name, "EE", 2) == 0) return &locale_ee_win;
        else if ((strncmp(name, "ES-LA", 5) == 0) || (strncmp(name, "ES_LA", 5) == 0)) return &locale_es_la_win;
        else if (strncmp(name, "ES", 2) == 0) return &locale_es_win;
        else if (strncmp(name, "FI", 2) == 0) return &locale_fi_win;
        else if (strncmp(name, "FR", 2) == 0) return &locale_fr_win;
        else if (strncmp(name, "GB", 2) == 0) return &locale_gb_win;
        else if (strncmp(name, "GR", 2) == 0) return &locale_gr_win;
        else if (strncmp(name, "HR", 2) == 0) return &locale_hr_win;
        else if (strncmp(name, "HU", 2) == 0) return &locale_hu_win;
        else if (strncmp(name, "IE", 2) == 0) return &locale_ie_win;
        else if (strncmp(name, "IN", 2) == 0) return &locale_in_win;
        else if (strncmp(name, "IS", 2) == 0) return &locale_is_win;
        else if (strncmp(name, "IT", 2) == 0) return &locale_it_win;
        else if (strncmp(name, "LT", 2) == 0) return &locale_lt_win;
        else if (strncmp(name, "LV", 2) == 0) return &locale_lv_win;
        else if (strncmp(name, "NL", 2) == 0) return &locale_nl_win;
        else if (strncmp(name, "NO", 2) == 0) return &locale_no_win;
        else if (strncmp(name, "PL", 2) == 0) return &locale_pl_win;
        else if ((strncmp(name, "PT-BR", 5) == 0) || (strncmp(name, "PT_BR", 5) == 0)) return &locale_pt_br_win;
        else if (strncmp(name, "PT", 2) == 0) return &locale_pt_win;
        else if (strncmp(name, "RO", 2) == 0) return &locale_ro_win;
        else if (strncmp(name, "RU", 2) == 0) return &locale_ru_win;
        else if (strncmp(name, "SE", 2) == 0) return &locale_se_win;
        else if (strncmp(name, "SI", 2) == 0) return &locale_si_win;
        else if (strncmp(name, "SK", 2) == 0) return &locale_sk_win;
        else if (strncmp(name, "TR", 2) == 0) return &locale_tr_win;
        else if (strncmp(name, "UA", 2) == 0) return &locale_ua_win;
        else if (strncmp(name, "US", 2) == 0) return &locale_us_win;

        else return nullptr;
    }
}