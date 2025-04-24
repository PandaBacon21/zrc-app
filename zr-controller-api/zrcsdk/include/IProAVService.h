/*!
 * \file IProAVService.h
 * \since Added in ZRC SDK 6.1.0
 * \brief Entrance of all the Pro AV Service.
 */
#ifndef ZRC_IPROAVSERVICE_H
#define ZRC_IPROAVSERVICE_H

#include "ZRCSDKTypes.h"

NS_ZRCSDK_BEG

/*! \enum ProAVVideoNameStrapPosition
    \brief Pro AV video overlay name strap position.
    Here are more detailed structural descriptions.
 */
enum ProAVVideoNameStrapPosition
{
    ProAVVideoNameStrapPositionUnknown = -1,    ///<Unknown.
    ProAVVideoNameStrapPositionLeft = 0,        ///<Left.
    ProAVVideoNameStrapPositionCenter = 1,      ///<Center.
    ProAVVideoNameStrapPositionRight = 2,       ///<Right.
};

/// \brief Pro AV video overlay settings.
///
struct ProAVVideoOverlaySettings
{
    bool isActiveSpeakerGreenOutlineEnabled = false;                            ///<TRUE indicates active speaker green outline is enabled.
    bool isReactionIconsEnabled = false;                                        ///<TRUE indicates reaction icons is enabled.
    bool isRaiseHandIconEnabled = false;                                        ///<TRUE indicates raise hand icon is enabled.
    bool isNameStrapEnabled = false;                                            ///<TRUE indicates name strap is enabled.
    ProAVVideoNameStrapPosition position= ProAVVideoNameStrapPositionUnknown;   ///<Name strap position, see \link ProAVVideoNameStrapPosition \endlink enum.
};

/// \brief Pro AV Service event callback.
///
class IProAVServiceSink
{
public:
    virtual ~IProAVServiceSink() {}

    /**
     * @since 6.2.0
     * @zrminver 6.2.0
     *
     * @brief Pro AV video overlay setting  notification callback.
     *
     * @param settings pro AV video overlay settings, see \link ProAVVideoOverlaySettings \endlink struct.
     */
    virtual void OnProAVVideoOverlaySettingsNotification(const ProAVVideoOverlaySettings& settings) = 0;
};

class IDanteOutputHelper;
class IHWIOHelper;

/// \brief Pro AV service interface.
///
class IProAVService
{
public:
    virtual ~IProAVService() {}

    /**
     * @since 6.2.0
     * @zrminver 6.2.0
     *
     * @brief Register pro AV service callback sink.
     *
     * @param pSink A pointer to the IProAVServiceSink that receives the premeeting service callback.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError RegisterSink(IProAVServiceSink* pSink) = 0;

    /**
     * @since 6.2.0
     * @zrminver 6.2.0
     *
     * @brief Deregister pro AV service callback sink.
     *
     * @param pSink A pointer to the IProAVServiceSink that receives the premeeting service callback.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError DeregisterSink(IProAVServiceSink* pSink) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Get the dante output helper.
     *
     * @return If the function succeeds, the return value is a pointer to IDanteOutputHelper. Otherwise the function returns NULL.
     */
    virtual IDanteOutputHelper* GetDanteOutputHelper() = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Get the HWIO helper.
     *
     * @return If the function succeeds, the return value is a pointer to IHWIOHelper. Otherwise the function returns NULL.
     */
    virtual IHWIOHelper* GetHWIOHelper() = 0;

    /**
     * @since 6.2.0
     * @zrminver 6.2.0
     *
     * @brief Query pro AV video overlay settings.
     *
     * @param[out] settings pro AV video overlay settings, see \link ProAVVideoOverlaySettings \endlink struct.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError GetProAVVideoOverlaySettings(ProAVVideoOverlaySettings& settings) = 0;

    /**
     * @since 6.2.0
     * @zrminver 6.2.0
     *
     * @brief Enable pro AV video active speaker green outline.
     *
     * @param enable TRUE indicates enable active speaker green outline. Otherwise disable.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError EnableProAVVideoActiveSpeakerGreenOutline(bool enable) = 0;

    /**
     * @since 6.2.0
     * @zrminver 6.2.0
     *
     * @brief Enable pro AV video reaction icons.
     *
     * @param enable TRUE indicates enable video reaction icons. Otherwise disable.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError EnableProAVVideoReactionIcons(bool enable) = 0;

    /**
     * @since 6.2.0
     * @zrminver 6.2.0
     *
     * @brief Enable pro AV video raise hand icon.
     *
     * @param enable TRUE indicates enable raise hand icon. Otherwise disable.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError EnableProAVVideoRaiseHandIcon(bool enable) = 0;

    /**
     * @since 6.2.0
     * @zrminver 6.2.0
     *
     * @brief Enable pro AV video name strap.
     *
     * @param enable TRUE indicates enable video name strap. Otherwise disable.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError EnableProAVVideoNameStrap(bool enable) = 0;

    /**
     * @since 6.2.0
     * @zrminver 6.2.0
     *
     * @brief Set pro AV video name strap position.
     *
     * @param position pro AV video name strap position, see \link ProAVVideoNameStrapPosition \endlink enum.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError SetProAVVideoNameStrapPosition(ProAVVideoNameStrapPosition position) = 0;
};


NS_ZRCSDK_END

#endif    // ZRC_IPROAVSERVICE_H
