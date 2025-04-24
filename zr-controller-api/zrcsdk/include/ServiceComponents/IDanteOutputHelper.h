/*!
 * \file IDanteOutputHelper.h
 * \since Added in ZRC SDK 6.1.0
 * \brief Dante output interfaces.
 */
#ifndef ZRC_IDANTEOUTPUTHELPER_H
#define ZRC_IDANTEOUTPUTHELPER_H

#include "ZRCSDKTypes.h"

NS_ZRCSDK_BEG

/*! \enum LocalNetworkAudioChannelType
    \brief Local network audio channel type.
    Here are more detailed structural descriptions.
*/
enum LocalNetworkAudioChannelType
{
    LocalNetworkAudioChannelTypeUnknown = -1,   ///<Local network audio channel type is unknown.
    LocalNetworkAudioChannelTypeRX = 0,         ///<Local network audio channel type is RX.
    LocalNetworkAudioChannelTypeTX = 1,         ///<Local network audio channel type is TX.
};

/*! \enum BroadcastConnectionState
    \brief Broadcast connection state. The state of connection between ZR's audio and channel.
    Here are more detailed structural descriptions.
*/
enum BroadcastConnectionState
{
    BroadcastConnectionStateDisconnected = 0,   ///<The connection state is disconnected.
    BroadcastConnectionStateConnected = 1,      ///<The connection state is connected.
};

/*! \enum AudioSignalType
    \brief Audio signal type.
    Here are more detailed structural descriptions.
*/
enum AudioSignalType
{
    AudioSignalTypeMono = 0,        ///<The audio signal type is Mono.
    AudioSignalTypeStereoLeft = 1,  ///<The audio signal type is StereoLeft.
    AudioSignalTypeStereoRight = 2, ///<The audio signal type is StereoRight.
};

/*! \enum AudioResourceType
    \brief Audio resource type. The type of the audio resource from ZR.
    Here are more detailed structural descriptions.
*/
enum AudioResourceType
{
    AudioResourceTypeIndividualUserAudio = 0,   ///<The audio resource type is individual user audio.
    AudioResourceTypeMixedAudio = 1,            ///<The audio resource type is mixed audio. The mixed audio refers to the total audio in the meeting.
    AudioResourceTypeShareContentAudio = 2,     ///<The audio resource type is share content audio. The share content audio refers to the total audio of share content. 
};

/// \brief Local network audio channel info.
/// 
struct LocalNetworkAudioChannelInfo
{
    std::string                   channelName;                                          ///<The channel name.
    int32_t                       channelID = 0;                                        ///<The channel ID.
    LocalNetworkAudioChannelType  channelType = LocalNetworkAudioChannelTypeUnknown;    ///<The channel type, such as \link LocalNetworkAudioChannelType \endlink enum.
    std::string                   networkDeviceName;                                    ///<The name of the network device which the channel belongs to.
};

/// \brief Local network audio device info.
///
struct LocalNetworkAudioDeviceInfo
{
    std::string                               networkDeviceName;    ///<The network device name. The device info is valid only when the networkDeviceName isn't empty.
    std::vector<LocalNetworkAudioChannelInfo> rxChannels;           ///The RX channels of the network device.
    std::vector<LocalNetworkAudioChannelInfo> txChannels;           ///The TX channels of the network device.
    bool                                      identifiable = false; ///TRUE indicates the network device is identifiable. Otherwise not.
};

/// \brief Network audio error.
/// The error will appear when you failed to create network audio device.
struct NetworkAudioError
{
    int32_t       errorCode = 0;    ///<The error code.
    std::string   errorName;        ///<The error name.
};

/// \brief Network audio broadcast connection info.
///
struct NetworkAudioBroadcastConnectionInfo
{
    int32_t                         userID = 0;                                             ///<The user ID. This filed is valid when you bind individual user to a channel.
    AudioResourceType               resourceType = AudioResourceTypeIndividualUserAudio;    ///<The audio resource type, such as \link AudioResourceType \endlink enum. 
    AudioSignalType                 signalType = AudioSignalTypeMono;                       ///<The audio signal type, such as \link AudioSignalType \endlink enum.
    LocalNetworkAudioChannelInfo    txChannel;                                              ///<The channel which the audio resource is bound to. 
    BroadcastConnectionState        state = BroadcastConnectionStateDisconnected;           ///<The broadcast connection state, such as \link BroadcastConnectionState \endlink enum.
};

/// \brief Dante output helper event callback.
///
class IDanteOutputHelperSink
{
public:
    virtual ~IDanteOutputHelperSink() {}

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Create local network audio device notification.
     *
     * @param result [0] Success. Otherwise Fail.
     * @param info The local network audio device info, details \link LocalNetworkAudioDeviceInfo \endlink.
     */
    virtual void OnCreateLocalNetworkAudioDevice(int32_t result, const LocalNetworkAudioDeviceInfo& info) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Destroy local network audio device notification.
     *
     * @param result [0] Success. Otherwise Fail.
     */
    virtual void OnDestroyLocalNetworkAudioDevice(int32_t result) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Local network audio error notification.
     *
     * @param error Local network audio error, details \link NetworkAudioError \endlink.
     */
    virtual void OnLocalNetworkAudioDeviceError(const NetworkAudioError& error) = 0;

    /**
     * @since 6.2.0
     * @zrminver 6.2.0
     *
     * @brief Local network audio info notification.
     *
     * @param info The local network audio device info, details \link LocalNetworkAudioDeviceInfo \endlink.
     */
    virtual void OnLocalNetworkAudioDeviceInfoNotification(const LocalNetworkAudioDeviceInfo& info) = 0;

    /**
     * @since 6.3.0
     * @zrminver 6.1.0
     *
     * @brief Bind user audio connection success notification.
     *
     * @param connections The connection between user audio and network audio device channel.
     */
    virtual void OnBindUserAudioConnectionSuccess(const std::vector<NetworkAudioBroadcastConnectionInfo>& connections) = 0;

    /**
     * @since 6.3.0
     * @zrminver 6.3.0
     *
     * @brief Bind user audio connection error notification.
     *
     * @param result Fail code.
     * @param userID The userID specifies which user's audio.
     * @param channel The channel which the user audio is bound to.
     * @param signalType The signal type of the user audio.
     */
    virtual void OnBindUserAudioConnectionError(int32_t result, int32_t userID, const LocalNetworkAudioChannelInfo& channel, AudioSignalType signalType) = 0;

    /**
     * @since 6.3.0
     * @zrminver 6.1.0
     *
     * @brief Unbind user audio connection success notification.
     *
     * @param connections The unbound connections about the specified type of the user audio.
     */
    virtual void OnUnbindUserAudioConnectionSuccess(const std::vector<NetworkAudioBroadcastConnectionInfo>& connections) = 0;

    /**
     * @since 6.3.0
     * @zrminver 6.3.0
     *
     * @brief Unbind user audio connection error notification.
     *
     * @param result Fail code.
     * @param userID The userID specifies which user's audio.
     * @param signalType The signal type of the user audio.
     */
    virtual void OnUnbindUserAudioConnectionError(int32_t result, int32_t userID, AudioSignalType signalType) = 0;

    /**
     * @since 6.3.0
     * @zrminver 6.1.0
     *
     * @brief Bind mixed audio connection success notification.
     *
     * @param connections The connection between mixed audio and network audio device channel.
     */
    virtual void OnBindMixedAudioConnectionSuccess(const std::vector<NetworkAudioBroadcastConnectionInfo>& connections) = 0;

    /**
     * @since 6.3.0
     * @zrminver 6.3.0
     *
     * @brief Bind mixed audio connection error notification.
     *
     * @param result Fail code.
     * @param channel The channel which the mixed audio is bound to.
     * @param signalType The signal type of the mixed audio.
     */
    virtual void OnBindMixedAudioConnectionError(int32_t result, const LocalNetworkAudioChannelInfo& channel, AudioSignalType signalType) = 0;

    /**
     * @since 6.3.0
     * @zrminver 6.1.0
     *
     * @brief Unbind mixed audio connection success notification.
     *
     * @param connections The unbound connections about the specified type of the mixed audio.
     */
    virtual void OnUnbindMixedAudioConnectionSuccess(const std::vector<NetworkAudioBroadcastConnectionInfo>& connections) = 0;

    /**
     * @since 6.3.0
     * @zrminver 6.3.0
     *
     * @brief Unbind mixed audio connection error notification.
     *
     * @param result Fail code.
     * @param signalType The signal type of the mixed audio.
     */
    virtual void OnUnbindMixedAudioConnectionError(int32_t result, AudioSignalType signalType) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Unbind all audio connection notification.
     *
     * @param result [0] Success. Otherwise Fail.
     * @param connections The unbound connections about all audio connection.
     */
    virtual void OnUnbindAllAudioConnection(int32_t result, const std::vector<NetworkAudioBroadcastConnectionInfo>& connections) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief List all audio connection notification.
     *
     * @param result [0] Success. Otherwise Fail.
     * @param connections The all audio connections.
     */
    virtual void OnListAllAudioConnection(int32_t result, const std::vector<NetworkAudioBroadcastConnectionInfo>& connections) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Update audio connection notification.
     *
     * @param connections The connection which needs to update.
     */
    virtual void OnUpdateAudioConnection(const std::vector<NetworkAudioBroadcastConnectionInfo>& connections) = 0;

    /**
     * @since 6.3.0
     * @zrminver 6.1.0
     *
     * @brief Unbind the audio in the specified channel success notification.
     *
     * @param connections The unbound connection which is in the specified channel.
     */
    virtual void OnUnbindChannelAudioConnectionSuccess(const std::vector<NetworkAudioBroadcastConnectionInfo>& connections) = 0;

    /**
     * @since 6.3.0
     * @zrminver 6.3.0
     *
     * @brief Unbind the audio in the specified channel error notification.
     *
     * @param result Fail code.
     * @param channel The channel which the mixed audio is bound to.
     */
    virtual void OnUnbindChannelAudioConnectionError(int32_t result, const LocalNetworkAudioChannelInfo& channel) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief List all unbind channel notification.
     *
     * @param result [0] Success. Otherwise Fail.
     * @param txChannels The channels which are unbound.
     */
    virtual void OnListAllUnbindChannel(int32_t result, const std::vector<LocalNetworkAudioChannelInfo>& txChannels) = 0;

    /**
     * @since 6.3.0
     * @zrminver 6.1.0
     *
     * @brief Bind share content connection success notification.
     *
     * @param connections The connection between the share content audio and network audio device channel.
     */
    virtual void OnBindShareContentAudioConnectionSuccess(const std::vector<NetworkAudioBroadcastConnectionInfo>& connections) = 0;

    /**
     * @since 6.3.0
     * @zrminver 6.3.0
     *
     * @brief Bind share content connection error notification.
     *
     * @param result Fail code.
     * @param channel The channel which the share content audio is bound to.
     * @param signalType The signal type of the share content audio.
     */
    virtual void OnBindShareContentAudioConnectionError(int32_t result, const LocalNetworkAudioChannelInfo& channel, AudioSignalType signalType) = 0;

    /**
     * @since 6.3.0
     * @zrminver 6.1.0
     *
     * @brief Unbind share content audio connection success notification.
     *
     * @param connections The unbound connections about the specified type of the share content audio.
     */
    virtual void OnUnbindShareContentAudioConnectionSuccess(const std::vector<NetworkAudioBroadcastConnectionInfo>& connections) = 0;

    /**
     * @since 6.3.0
     * @zrminver 6.3.0
     *
     * @brief Unbind share content audio connection error notification.
     *
     * @param result Fail code.
     * @param signalType The signal type of the share content.
     */
    virtual void OnUnbindShareContentAudioConnectionError(int32_t result, AudioSignalType signalType) = 0;
};

/// \brief Dante Output helper interface.
///
class IDanteOutputHelper
{
public:
    virtual ~IDanteOutputHelper() {}

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Register dante output helper callback sink.
     *
     * @param pSink A pointer to the IDanteOutputHelperSink that receives the dante output helper callback.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError RegisterSink(IDanteOutputHelperSink* pSink) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Deregister meeting dante output callback sink.
     *
     * @param pSink A pointer to the IDanteOutputHelperSink that receives the dante output helper callback.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError DeregisterSink(IDanteOutputHelperSink* pSink) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Check if support dante output feature.
     *
     * @param[out] isSupport TRUE indicates support dante output feature. Otherwise not.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError IsSupportDanteOutput(bool& isSupport) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Create local network audio device. You can call GetLocalNetworkAudioDeviceInfo API to check if exist local network device before you call this API.
     *
     * @param name The name of the local network audio device.
     * @param rxChannelCount The RX channel count of the local network audio device.
     * @param txChannelCount The TX channel count of the local network audio device.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError CreateLocalNetworkAudioDevice(const std::string& name, int32_t rxChannelCount = 8, int32_t txChannelCount = 8) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Destroy local network audio device.
     *
     * @param name The name of the local network audio device which will be destroyed.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError DestroyLocalNetworkAudioDevice(const std::string& name) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Bind user audio to a channel.
     *
     * @param userID The userID specifies which user's audio.
     * @param channel The channel which the user audio is bound to.
     * @param signalType The signal type of the user audio.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError BindUserAudioConnection(int32_t userID, const LocalNetworkAudioChannelInfo& channel, AudioSignalType signalType = AudioSignalTypeMono) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Unbind user audio.
     *
     * @param userID The userID specifies which user's audio.
     * @param signalType The signal type of the user audio.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError UnbindUserAudioConnection(int32_t userID, AudioSignalType signalType) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Bind mixed audio to a channel. The mixed audio refers to the total audio in the meeting.
     *
     * @param channel The channel which the mixed audio is bound to.
     * @param signalType The signal type of the mixed audio.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError BindMixedAudioConnection(const LocalNetworkAudioChannelInfo& channel, AudioSignalType signalType) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Unbind mixed audio.
     *
     * @param signalType The signal type of the mixed audio.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError UnbindMixedAudioConnection(AudioSignalType signalType) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Bind share content audio to a channel. The share content audio refers to the total audio of share content.
     *
     * @param channel The channel which the share content audio is bound to.
     * @param signalType The signal type of the share content audio.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError BindShareContentAudioConnection(const LocalNetworkAudioChannelInfo& channel, AudioSignalType signalType) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Unbind share content audio.
     *
     * @param signalType The signal type of the share content.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError UnbindShareContentAudioConnection(AudioSignalType signalType) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Unbind all audio connection.
     *
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError UnbindAllAudioConnection() = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief List all audio connection.
     *
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError ListAllAudioConnection() = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Unbind the audio in the specified channel.
     *
     * @param channel The channel specifies which channel will unbind the audio.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError UnbindChannelAudio(const LocalNetworkAudioChannelInfo& channel) = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief List all unbind channel.
     *
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError ListAllUnbindChannel() = 0;

    /**
     * @since 6.1.0
     * @zrminver 6.1.0
     *
     * @brief Get local network audio device info.
     *
     * @param[out] info The local network audio device info.
     * @return If the function succeeds, the return value is @ref ZRCSDKERR_SUCCESS.
     * Otherwise failed. To get extended error information, see \link ZRCSDKError \endlink enum.
     */
    virtual ZRCSDKError GetLocalNetworkAudioDeviceInfo(LocalNetworkAudioDeviceInfo& info) = 0;
};

NS_ZRCSDK_END

#endif
