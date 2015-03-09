/****************************************************************************
 Copyright (c) 2013 cocos2d-x.org
 Copyright (c) Microsoft Open Technologies, Inc.

 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __Updater__
#define __Updater__

#include "cocos2d.h"
#include "ExtensionMacros.h"

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT) && (CC_TARGET_PLATFORM != CC_PLATFORM_WP8)
#include <string>
#include <curl/curl.h>
#include <pthread.h>

NS_CC_EXT_BEGIN

class UpdaterDelegateProtocol;

/*
 *  This class is used to auto update resources, such as pictures or scripts.
 *  The updated package should be a zip file. And there should be a file named
 *  version in the server, which contains version code.
 *  @js NA
 *  @lua NA
 */
class CC_DLL Updater
{
public:
    enum ErrorCode
    {
        // Error caused by creating a file to store downloaded data
        kCreateFile,
        /** Error caused by network
         -- network unavaivable
         -- timeout
         -- ...
         */
        kNetwork,
        /** Error caused in uncompressing stage
         -- can not open zip file
         -- can not read file global information
         -- can not read file information
         -- can not create a directory
         -- ...
         */
        kUncompress,
    };
    
    enum StateCode
    {
        kDownStart,
        kDownDone,
        kUncompressStart,
        kUncompressDone,
    };
    
    enum TypeCode
    {
        kUpdateUndefined,
        kUpdateZIP,
        kUpdateFiles,
        kUpdateFile,
        kUpdateFileAsync,
    };
    
    /* @brief Creates a Updater.
     */
    Updater();
    
    virtual ~Updater();
    
    /* @brief Download new package zip file, and uncompress downloaded zip file.
     */
    void update(const char* zipUrl, const char* zipFile, const char* unzipTmpDir, bool resetBeforeUnZIP=true);
    
    /** @brief Download some files.
     */
    void update(CCArray* list);
    
    /** @brief Download a file and save to filePath.
     */
    void update(const char* fileUrl, const char* filePath);

    /** @brief Download a file in async.
     */
    void update(const char* fileUrl);
    
    /** @brief Sets delegate, the delegate will receive messages
     */
    void setDelegate(UpdaterDelegateProtocol *delegate);
    
    /** @brief Register script handler, the hander will receive messages
     */
    void registerScriptHandler(int handler);
    void unregisterScriptHandler(void);

    /** @brief Sets connection time out in seconds
     */
    void setConnectionTimeout(unsigned int timeout);
    
    /** @brief Gets connection time out in secondes
     */
    unsigned int getConnectionTimeout();
    bool createDirectory(const char *path);
    bool removeDirectory(const char* path);
    void removeFileWithName(const char* name);
    const char* getUpdateInfo(const char* url);
    
    /* An entry of a new thresd. */
    friend void* updateThreadFunc(void*);
    
    friend int downloadProgressFunc(void *, double, double, double, double);
    
protected:
    bool download(const char* fileUrl, const char* filePath);
    bool uncompress(const char* zipFile, const char* unzipTmpDir, bool resetBeforeUnZIP);
    void sendErrorMessage(ErrorCode code);
    void sendStateMessage(StateCode code);
    void sendSuccMessage();
    
    void checkUnZIPTmpDir();
    void clearOnSuccess();
    
    std::string _unzipTmpDir;
    std::string _updateInfoString;
    bool _resetBeforeUnZIP;
    
    std::string _fileUrl;
    std::string _filePath;
    TypeCode _updateType;
    
private:
    void clearTid();
    bool isAvailable();
    
    typedef struct _Message
    {
    public:
        _Message() : what(0), obj(NULL){}
        unsigned int what; // message type
        void* obj;
    } Message;
    
    class Helper : public cocos2d::CCObject
    {
    public:
        Helper();
        ~Helper();
        
        virtual void update(float dt);
        void sendMessage(Message *msg);
        
    private:
        void handleUpdateSucceed(Message *msg);
        void handlerState(Message* msg);
        void handlerError(Message* msg);
        void handlerProgress(Message* msg);
        
        std::list<Message*> *_messageQueue;
        pthread_mutex_t _messageQueueMutex;
    };
    
private:
    //! The path to store downloaded resources.
    std::string _storagePath;

    CURL *_curl;
    Helper *_schedule;
    pthread_t *_tid;
    unsigned int _connectionTimeout;
    
    UpdaterDelegateProtocol *_delegate; // weak reference
    int _scriptHandler; // script handler
};

class UpdaterDelegateProtocol
{
public:
    /* @brief Call back function for error
       @param errorCode Type of error
     */
    virtual void onError(Updater::ErrorCode errorCode) {};
    /** @brief Call back function for recording downloading percent
        @param percent How much percent downloaded
        @warn This call back function just for recording downloading percent.
              Updater will do some other thing after downloading, you should
              write code in onSuccess() after downloading. 
     */
    virtual void onProgress(int percent) {};
    /** @brief Call back function for success
     */
    virtual void onSuccess() {};
    virtual void onState(Updater::StateCode stateCode) {};
};

NS_CC_EXT_END;
#endif // CC_TARGET_PLATFORM != CC_PLATFORM_WINRT
#endif /* defined(__Updater__) */