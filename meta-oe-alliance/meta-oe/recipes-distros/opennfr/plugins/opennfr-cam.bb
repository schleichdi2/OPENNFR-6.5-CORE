DESCRIPTION = "OpenNFR Cam files"
LICENSE = "GPL2"

require conf/license/license-gplv2.inc

PACKAGE_ARCH := "${MACHINE_ARCH}"

SRCREV = "${AUTOREV}"

SRC_URI = "file://*"

FILES_${PN} = "/var* /usr/bin/* /usr/lib/python2.7/* /usr/lib/python2.7/site-packages/twisted/web/* /usr/emu/* /usr/keys/* /usr/share/enigma2/defaults/* /usr/share/enigma2/* /usr/share/enigma2/rc_models/ini4/* /usr/share/enigma2/rc_models/red2/* /usr/share/enigma2/po/de/LC_MESSAGES/* /usr/lib/enigma2/python/Components/Converter/* /usr/lib/enigma2/python/Plugins/Extensions/Infopanel/data/* /usr/lib/enigma2/python/Plugins/Extensions/Infopanel/* /usr/scripts/*"
S = "${WORKDIR}"

do_install() {

    install -d ${D}/usr/emu
    for f in CCcam230.tar.gz oscam.tar.gz oscam-arm.tar.gz
    do
        install -m 755 ${f} ${D}/usr/emu/${f}
    done

    install -d ${D}/usr/scripts
    for f in feed_install.sh devfeed_install.sh
    do
        install -m 755 ${f} ${D}/usr/scripts/${f}
    done

    install -d ${D}/usr/keys
    for f in CCcam.cfg SoftCam.Key oscam.conf oscam.keys oscam.provid oscam.server oscam.services oscam.srvid oscam.user softcam.cfg oscam.dvbapi oscam.ccache
    do
        install -m 644 ${f} ${D}/usr/keys/${f}
    done

    install -d ${D}/usr/share/enigma2/defaults
    for f in bouquets* userbouquet* autotimer.xml cert.pem key.pem lamedb lamedb5 menusort.xml pluginsort.xml subservices.xml blacklist whitelist
    do
        install -m 644 ${f} ${D}/usr/share/enigma2/defaults/${f}
    done
    
    install -d ${D}/usr/share/enigma2/po/de/LC_MESSAGES
    for f in enigma2-neu.mo
    do
        install -m 644 ${f} ${D}/usr/share/enigma2/po/de/LC_MESSAGES/${f}
    done

}
do_populate_sysroot[noexec] = "1"
do_package_qa[noexec] = "1"
