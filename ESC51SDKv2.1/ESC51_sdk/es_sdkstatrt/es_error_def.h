/***********************************************************************************************************************
 *                                                      ESourceOpen
 *                                           -----------------------------------
 *                                           explore and open  embedded platform
 * 
 * Contact information:
 * e-mail: 1786409879@qq.com / txh17778443952@169.com
 *                                                                                 +-------------+---------------------+
 * ESourceOpen：                                                                   |   founder   |       TXHopen       |
 *   The ESource plan is a difficult and long-term plan. This plan                 +-------------+---------------------+
 *   does not limit the use of code, only to provide an open platform              |   encode    |    UTF-8 / utf-8    |
 *   to explore the software development of embedded platforms.                    +-------------+---------------------+
***********************************************************************************************************************/
/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      es_error_def.h
 * 
 * @brief     SDK初始化bsp头文件
 * 
 * @version   V0.00.01
 * 
 * @author    TXHopen (3332695529@qq.com)
 * 
 * @date      2021-08-08
 * 
 * @copyright Copyright (c) 2021
 * 
 * *****************************************************ESourceOPEN*****************************************************
 * 
 * *****************************************************ESourceOPEN*****************************************************
 **/
#ifndef __ES_ERROR_DEF_H
#define __ES_ERROR_DEF_H


typedef enum __error_type {
    ES_OK = 0,                     /**< \brief 正确 */
    ES_ERROR,                      /**< \brief 错误 */
    
    ES_EINVAL,                     /**< \brief 参数无效 */
    ES_EOVFLOW,                    /**< \brief 溢出 */
    ES_ENULLP,                     /**< \brief 空指针 */
  
    ES_EPERM,                      /**< \brief 操作不允许 */
    ES_ENOENT,                     /**< \brief 没有文件或目录 */
    ES_ESRCH,                      /**< \brief 没有这样的过程 */
    ES_EINTR,                      /**< \brief 系统调用被中断 */
    ES_ENXIO,                      /**< \brief 没有这样的设备或地址 */
    ES_E2BIG,                      /**< \brief 参数列表太长 */
    ES_ENOEXEC,                    /**< \brief 操作不允许 */
    ES_EBADF,                      /**< \brief 坏的文件描述符 */
    ES_ECHILD,                     /**< \brief 没有子进程 */
    ES_EAGAIN,                     /**< \brief 操作不允许 */
    ES_ENOMEM,                     /**< \brief 操作不允许 */
    ES_EACCES,                     /**< \brief 拒绝许可 */
    ES_EFAULT,                     /**< \brief 错误的地址 */
    ES_ENOTBLK,                    /**< \brief 块设备请求 */
    ES_EBUSY,                      /**< \brief 设备或资源忙 */
    ES_EEXIST,                     /**< \brief 文件存在 */
    ES_EXDEV,                      /**< \brief 无效的交叉链接 */
    ES_ENODEV,                     /**< \brief 设备不存在 */
    ES_ENOTDIR,                    /**< \brief 不是一个目录 */
    ES_EISDIR,                     /**< \brief 是一个目录 */
    ES_EINVAL,                     /**< \brief 无效的参数 */
    ES_ENFILE,                     /**< \brief 打开太多的文件系统 */
    ES_EMFILE,                     /**< \brief 打开的文件过多 */
    ES_ENOTTY,                     /**< \brief 不是tty设备 */
    ES_ETXTBSY,                    /**< \brief 文本文件忙 */
    ES_EFBIG,                      /**< \brief 文件太大 */
    ES_ENOSPC,                     /**< \brief 设备上没有空间 */
    ES_ESPIPE,                     /**< \brief 非法移位 */
    ES_EROFS,                      /**< \brief 只读文件系统 */
    ES_EMLINK,                     /**< \brief 太多的链接 */
    ES_EPIPE,                      /**< \brief 管道破裂 */
    ES_EDOM,                       /**< \brief 数值结果超出范围 */
    ES_ERANGE,                     /**< \brief 数值结果不具代表性 */
    ES_EDEADLK,                    /**< \brief 资源死锁错误 */
    ES_ENAMETOOLONG,               /**< \brief 文件名太长 */
    ES_ENOLCK,                     /**< \brief 没有可用锁 */
    ES_ENOSYS,                     /**< \brief 功能没有实现 */
    ES_ENOTEMPTY,                  /**< \brief 目录不空 */
    ES_ELOOP,                      /**< \brief 符号链接层次太多 */
    ES_EWOULDBLOCK,                /**< \brief 和EAGAIN一样 */
    ES_ENOMSG,                     /**< \brief 没有期望类型的消息 */
    ES_EIDRM,                      /**< \brief 标识符删除 */
    ES_ECHRNG,                     /**< \brief 频道数目超出范围 */
    ES_EL2NSYNC,                   /**< \brief 2级不同步 */
    ES_EL3HLT,                     /**< \brief 3级中断 */
    ES_EL3RST,                     /**< \brief 3级复位 */
    ES_ELNRNG,                     /**< \brief 链接数超出范围 */
    ES_EUNATCH,                    /**< \brief 协议驱动程序没有连接 */
    ES_ENOCSI,                     /**< \brief 没有可用CSI结构 */
    ES_EL2HLT,                     /**< \brief 2级中断 */
    ES_EBADE,                      /**< \brief 无效的交换 */
    ES_EBADR,                      /**< \brief 请求描述符无效 */
    ES_EXFULL,                     /**< \brief 交换全 */
    ES_ENOANO,                     /**< \brief 没有阳极 */
    ES_EBADRQC,                    /**< \brief 无效的请求代码 */
    ES_EBADSLT,                    /**< \brief 无效的槽 */
    ES_EDEADLOCK,                  /**< \brief 和EDEADLK一样 */
    ES_EBFONT,                     /**< \brief 错误的字体文件格式 */
    ES_ENOSTR,                     /**< \brief 设备不是字符流 */
    ES_ENODATA,                    /**< \brief 无可用数据 */
    ES_ETIME,                      /**< \brief 计时器过期 */
    ES_ENOSR,                      /**< \brief 流资源溢出 */
    ES_ENONET,                     /**< \brief 机器不上网 */
    ES_ENOPKG,                     /**< \brief 没有安装软件包 */
    ES_EREMOTE,                    /**< \brief 对象是远程的 */
    ES_ENOLINK,                    /**< \brief 联系被切断 */
    ES_EADV,                       /**< \brief 广告的错误 */
    ES_ESRMNT,                     /**< \brief srmount错误 */
    ES_ECOMM,                      /**< \brief 发送时的通讯错误 */
    ES_EPROTO,                     /**< \brief 协议错误 */
    ES_EMULTIHOP,                  /**< \brief 多跳尝试 */
    ES_EDOTDOT,                    /**< \brief RFS特定的错误 */
    ES_EBADMSG,                    /**< \brief 非数据消息 */
    ES_EOVERFLOW,                  /**< \brief 值太大,对于定义数据类型 */
    ES_ENOTUNIQ,                   /**< \brief 名不是唯一的网络 */
    ES_EBADFD,                     /**< \brief 文件描述符在坏状态 */
    ES_EREMCHG,                    /**< \brief 远程地址改变了 */
    ES_ELIBACC,                    /**< \brief 无法访问必要的共享库 */
    ES_ELIBBAD,                    /**< \brief 访问损坏的共享库 */
    ES_ELIBSCN,                    /**< \brief 库段. out损坏 */
    ES_ELIBMAX,                    /**< \brief 试图链接太多的共享库 */
    ES_ELIBEXEC,                   /**< \brief 不能直接执行一个共享库 */
    ES_EILSEQ,                     /**< \brief 无效的或不完整的多字节或宽字符 */
    ES_ERESTART,                   /**< \brief 应该重新启动中断的系统调用 */
    ES_ESTRPIPE,                   /**< \brief 流管错误 */
    ES_EUSERS,                     /**< \brief 用户太多 */
    ES_ENOTSOCK,                   /**< \brief 套接字操作在非套接字上 */
    ES_EDESTADDRREQ,               /**< \brief 需要目标地址 */
    ES_EMSGSIZE,                   /**< \brief 消息太长 */
    ES_EPROTOTYPE,                 /**< \brief socket协议类型错误 */
    ES_ENOPROTOOPT,                /**< \brief 协议不可用 */
    ES_EPROTONOSUPPORT,            /**< \brief 不支持的协议 */
    ES_ESOCKTNOSUPPORT,            /**< \brief 套接字类型不受支持 */
    ES_EOPNOTSUPP,                 /**< \brief 不支持的操作 */
    ES_EPFNOSUPPORT,               /**< \brief 不支持的协议族 */
    ES_EAFNOSUPPORT,               /**< \brief 协议不支持的地址 */
    ES_EADDRINUSE,                 /**< \brief 地址已在使用 */
    ES_EADDRNOTAVAIL,              /**< \brief 无法分配请求的地址 */
    ES_ENETDOWN,                   /**< \brief 网络瘫痪 */
    ES_ENETUNREACH,                /**< \brief 网络不可达 */
    ES_ENETRESET,                  /**< \brief 网络连接丢失 */
    ES_ECONNABORTED,               /**< \brief 软件导致连接中断 */
    ES_ECONNRESET,                 /**< \brief 连接被重置 */
    ES_ENOBUFS,                    /**< \brief 没有可用的缓冲空间 */
    ES_EISCONN,                    /**< \brief 传输端点已经连接 */
    ES_ENOTCONN,                   /**< \brief 传输终点没有连接 */
    ES_ESHUTDOWN,                  /**< \brief 传输后无法发送 */
    ES_ETOOMANYREFS,               /**< \brief 太多的参考 */
    ES_ETIMEDOUT,                  /**< \brief 连接超时 */
    ES_ECONNREFUSED,               /**< \brief 拒绝连接 */
    ES_EHOSTDOWN,                  /**< \brief 主机已关闭 */
    ES_EHOSTUNREACH,               /**< \brief 没有主机的路由 */
    ES_EALREADY,                   /**< \brief 已运行 */
    ES_EINPROGRESS,                /**< \brief 正在运行 */
    ES_ESTALE,                     /**< \brief 陈旧的NFS文件句柄 */
    ES_EUCLEAN,                    /**< \brief 结构需要清洗 */
    ES_ENOTNAM,                    /**< \brief 不是XENIX命名的 */
    ES_ENAVAIL,                    /**< \brief 没有XENIX信号量 */
    ES_EISNAM,                     /**< \brief 是一个命名的文件类型 */
    ES_EREMOTEIO,                  /**< \brief 远程输入/输出错误 */
    ES_EDQUOT,                     /**< \brief 超出磁盘配额 */
    ES_ENOMEDIUM,                  /**< \brief 没有磁盘被发现 */
    ES_EMEDIUMTYPE,                /**< \brief 错误的媒体类型 */
    ES_ECANCELED,                  /**< \brief 取消操作 */
    ES_ENOKEY,                     /**< \brief 所需键不可用 */
    ES_EKEYEXPIRED,                /**< \brief 关键已过期 */
    ES_EKEYREVOKED,                /**< \brief 关键被撤销 */
    ES_EKEYREJECTED,               /**< \brief 关键被拒绝服务 */
    ES_EOWNERDEAD,                 /**< \brief 所有者死亡 */
    ES_ENOTRECOVERABLE,            /**< \brief 状态不可恢复 */
    ES_ERFKILL,                    /**< \brief 由于RF-kill而无法操作 */
} es_err_t;



#endif /* __ES_ERROR_DEF_H */
