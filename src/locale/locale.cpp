/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "locale.h"

#include "locale_us.h"
#include "locale_de.h"
#include "locale_gb.h"
#include "locale_es.h"
#include "locale_fr.h"
#include "locale_ru.h"
#include "locale_dk.h"
#include "locale_be.h"
#include "locale_pt.h"
#include "locale_it.h"

#include <cstring> // strncmp

namespace locale
{
    // ===== PUBLIC ===== //
    hid_locale_t *get_default()
    {
        return &locale_us;
    }

    hid_locale_t *get(const char *name)
    {
        if (strncmp(name, "US", 2) == 0)
        {
            return &locale_us;
        }
        else if (strncmp(name, "DE", 2) == 0)
        {
            return &locale_de;
        }
        else if (strncmp(name, "GB", 2) == 0)
        {
            return &locale_gb;
        }
        else if (strncmp(name, "ES", 2) == 0)
        {
            return &locale_es;
        }
        else if (strncmp(name, "FR", 2) == 0)
        {
            return &locale_fr;
        }
        else if (strncmp(name, "RU", 2) == 0)
        {
            return &locale_ru;
        }
        else if (strncmp(name, "DK", 2) == 0)
        {
            return &locale_dk;
        }
        else if (strncmp(name, "BE", 2) == 0)
        {
            return &locale_be;
        }
        else if (strncmp(name, "PT", 2) == 0)
        {
            return &locale_pt;
        }
        else if (strncmp(name, "IT", 2) == 0)
        {
            return &locale_it;
        }
        else
        {
            return nullptr;
        }
    }
}