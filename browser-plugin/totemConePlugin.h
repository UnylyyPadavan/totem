/* Totem Cone Plugin
 *
 * Copyright (C) 2004 Bastien Nocera <hadess@hadess.net>
 * Copyright (C) 2002 David A. Schleef <ds@schleef.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * $Id: totemBasicPlugin.h 3717 2006-11-15 17:21:16Z chpe $
 */

#ifndef __CONE_PLUGIN_H__
#define __CONE_PLUGIN_H__

#include <nsIClassInfo.h>

#include "totemICone.h"
#include "totemPlugin.h"

class totemScriptablePlugin : public totemICone,
			      public nsIClassInfo
{
  public:
    NS_DECL_ISUPPORTS
    NS_DECL_TOTEMICONE
    NS_DECL_NSICLASSINFO

    totemScriptablePlugin (totemPlugin *aPlugin);

    PRBool IsValid () { return mPlugin != nsnull; }
    void SetPlugin (totemPlugin *aPlugin) { mPlugin = aPlugin; }

    static char *PluginDescription ();
    static void PluginMimeTypes (const totemPluginMimeEntry **, PRUint32 *);
  private:
    ~totemScriptablePlugin ();

    totemPlugin *mPlugin;
};

#endif /* __CONE_PLUGIN_H__ */